from setuptools import setup, find_packages, Extension
from distutils.sysconfig import get_python_inc
import glob
import os
import re
import sys
import ast
import io

GMCPP_PC = 'GraphicsMagick++.pc'
IMCPP_PC = 'ImageMagick++.pc'
LIBRARY = 'GraphicsMagick'  # default value
include_dirs = [get_python_inc()]
library_dirs = []

search_include_dirs = ['/usr/local/include/GraphicsMagick/',
                       '/usr/include/GraphicsMagick/']
search_library_dirs = ['/usr/local/lib64/', '/usr/lib64/',
                       '/usr/local/lib/', '/usr/lib/']
search_pkgconfig_dirs = ['/usr/local/lib/pkgconfig/', '/usr/local/lib64/pkgconfig/',
                         '/usr/lib/pkgconfig/', '/usr/lib64/pkgconfig']
if sys.platform.lower() == 'darwin':
    if os.path.exists('/opt/local/include'):
        include_dirs.append('/opt/local/include/')
    else:
        include_dirs.append('/usr/local/include/')
    search_include_dirs.extend(['/opt/local/include/GraphicsMagick/',
                                '/opt/local/include/',
                                '/usr/local/Cellar/graphicsmagick'])
    search_library_dirs.extend(['/opt/local/lib/',
                                '/usr/local/Cellar/graphicsmagick'])
# for ImageMagick
search_include_dirs.extend(['/usr/local/include/ImageMagick/',
                            '/usr/include/ImageMagick/'])
if sys.platform.lower() == 'darwin':
    search_include_dirs.append('/opt/local/include/ImageMagick/')


if 'MAGICK_HOME' in os.environ:
    extra_include_dir = os.path.join(os.environ['MAGICK_HOME'], 'include')
    print('adding extra include directory %s' % extra_include_dir)
    search_include_dirs.insert(0, extra_include_dir)

    extra_library_dir = os.path.join(os.environ['MAGICK_HOME'], 'lib')
    print('adding extra library directory %s' % extra_library_dir)
    search_library_dirs.insert(0, extra_library_dir)

    extra_pkgconfig_dir = os.path.join(extra_library_dir, 'pkgconfig')
    print('adding extra pkgconfig directory %s' % extra_pkgconfig_dir)
    search_pkgconfig_dirs.insert(0, extra_pkgconfig_dir)


def _grep(regex, filename):
    for line in open(filename):
        if re.search(regex, line):
            return line


def get_version_from_devheaders(search_dirs):
    target_api_name = "addNoiseChannel"
    for dirname in search_dirs:
        for root, dirs, files in os.walk(dirname):
            for f in files:
                if f == 'Image.h':
                    if _grep(target_api_name, os.path.join(root, 'Image.h')):
                        return '1.2.0'


def get_version_from_pc(search_dirs, target):
    """similar to 'pkg-config --modversion GraphicsMagick++'"""
    for dirname in search_dirs:
        for root, dirs, files in os.walk(dirname):
            for f in files:
                if f == target:
                    file_path = os.path.join(root, target)
                    _tmp = _grep("Version: ", file_path)
                    version = _tmp.split()[1]
                    print("Found version %s in file %s" % (version, file_path))
                    return version


def find_file(filename, search_dirs):
    for dirname in search_dirs:
        for root, dirs, files in os.walk(dirname):
            for f in files:
                if filename in f:
                    return root
            for d in dirs:
                if filename in d:
                    return root
            if filename in root:
                return root
    return False


def library_supports_api(library_version, api_version, different_major_breaks_support=True):
    """
    Returns whether api_version is supported by given library version.
    E. g.  library_version (1,3,21) returns True for api_version (1,3,21), (1,3,19), (1,3,'x'), (1,2,'x'), (1, 'x')
           False for (1,3,24), (1,4,'x'), (2,'x')

    different_major_breaks_support - if enabled and library and api major versions are different always return False
           ex) with library_version (2,0,0) and for api_version(1,3,24) returns False if enabled, True if disabled
    """
    assert isinstance(library_version, (tuple, list))  # won't work with e.g. generators
    assert len(library_version) == 3
    sequence_type = type(library_version)  # assure we will compare same types
    api_version = sequence_type(0 if num == 'x' else num for num in api_version)
    if different_major_breaks_support and library_version[0] != api_version[0]:
        return False
    assert len(api_version) <= 3     # otherwise following comparision won't work as intended, e.g. (2, 0, 0) > (2, 0, 0, 0)
    return library_version >= api_version

# find to header path
header_path = find_file('Magick++.h', search_include_dirs)
if not header_path:
    raise Exception("Magick++ not found")
print("include header path: %s" % header_path)
include_dirs.append(header_path)

# find to library path for boost_python
# TODO: only test on Ubuntu11.10
_python_version = sys.version_info

boost_lib_target_files = []
if _python_version >= (3, ):
    boost_lib_target_files.append("boost_python-py%s%s" % (_python_version[0], _python_version[1]))
    # ArchLinux uses boost_python3
    boost_lib_target_files.append("boost_python3")
    boost_lib_target_files.append("boost_python3-mt")
boost_lib_target_files.append("boost_python-mt-py%s%s" % (_python_version[0], _python_version[1]))
# gentoo appends the python version numbers to the boost_python libraries
boost_lib_target_files.append("boost_python-%s.%s" % (_python_version[0], _python_version[1]))
boost_lib_target_files.append("boost_python-mt")

for boost_lib in boost_lib_target_files:
    lib_path = find_file('lib' + boost_lib, search_library_dirs)
    if lib_path:
        break

if not lib_path:
    boost_lib = "boost_python"
print("boost lib: %s" % boost_lib)

libraries = [boost_lib]

# find to library path for Magick
lib_path = find_file('libGraphicsMagick++', search_library_dirs)
if lib_path:
    libraries.append('GraphicsMagick++')
    print("library path: %s" % (os.path.join(lib_path, "libGraphicsMagick++")))
else:
    lib_path = find_file('libMagick++', search_library_dirs)
    if lib_path:
        LIBRARY = 'ImageMagick'
        libraries.append('Magick++')
        print("library path: %s" % (os.path.join(lib_path, "libMagick++")))
    else:
        raise Exception("libGraphicsMagick++ (or libMagick++) not found")
library_dirs.append(lib_path)

# get version and extra compile argument
ext_compile_args = []
if LIBRARY == 'GraphicsMagick':
    _version = get_version_from_pc(search_pkgconfig_dirs + search_include_dirs, GMCPP_PC)
else:
    _version = get_version_from_pc(search_pkgconfig_dirs + search_include_dirs, IMCPP_PC)
if not _version:
    _version = get_version_from_devheaders(include_dirs)
if _version:
    _str_version = _version
    print("%s version: %s" % (LIBRARY, _version))
    _version = list(map(int, _version.split('.')))
    if len(_version) == 2:
        # ex) 1.2 -> 1.2.0
        _version.append(0)
    if LIBRARY == 'GraphicsMagick':
        # 1.3.6 for not Ubuntu10.04
        _tested_api_versions = ((1,3,27), (1,3,26), (1,3,24), (1,3,22), (1,3,20), (1,3,19), (1,3,6), (1,3,'x'))
        _supported_api_versions = (v for v in _tested_api_versions if library_supports_api(_version, v))
        ext_compile_args = ["-DPGMAGICK_LIB_GRAPHICSMAGICK_" + '_'.join(map(str, version)) for version in _supported_api_versions]
    elif LIBRARY == 'ImageMagick':
        ext_compile_args = ["-DPGMAGICK_LIB_IMAGEMAGICK"]
    ext_compile_args.append("-D_LIBRARY_VERSION=\"%s\"" % (_str_version))
else:
    _version = '%s version: ???' % (LIBRARY)


def version():
    """Return version string."""
    with io.open('pgmagick/_version.py') as input_file:
        for line in input_file:
            if line.startswith('__version__'):
                return ast.parse(line).body[0].value.s


setup(name='pgmagick',
      version=version(),
      description="Yet Another Python wrapper for GraphicsMagick",
      long_description=open('README.rst').read(),
      author='Hideo Hattori',
      author_email='hhatto.jp@gmail.com',
      url='https://github.com/hhatto/pgmagick',
      license='MIT',
      packages=find_packages(),
      ext_modules=[
          Extension('pgmagick._pgmagick',
                    sources=glob.glob('./src/*.cpp'),
                    include_dirs=include_dirs,
                    library_dirs=library_dirs,
                    libraries=libraries,
                    extra_compile_args=ext_compile_args)],
      classifiers=[
          'Development Status :: 4 - Beta',
          'Intended Audience :: Developers',
          'License :: OSI Approved :: MIT License',
          'Operating System :: POSIX',
          'Programming Language :: C++',
          'Programming Language :: Python',
          'Programming Language :: Python :: 3',
          'Topic :: Multimedia :: Graphics'],
      keywords="GraphicsMagick ImageMagick graphics boost image")
