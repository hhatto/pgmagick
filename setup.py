from setuptools import setup, find_packages, Extension
from distutils.sysconfig import get_python_inc
import glob
import os
import re
import sys

GMCPP_PC = 'GraphicsMagick++.pc'
IMCPP_PC = 'ImageMagick++.pc'
LIBRARY = 'GraphicsMagick'  # default value
include_dirs = [get_python_inc()]
library_dirs = []

search_include_dirs = ['/usr/local/include/GraphicsMagick/',
                       '/usr/include/GraphicsMagick/']
search_library_dirs = ['/usr/local/lib64/', '/usr/lib64/',
                       '/usr/local/lib/', '/usr/lib/']
if sys.platform.lower() == 'darwin':
    include_dirs.append('/opt/local/include/')
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
    search_dirs.append('/usr/local/lib/pkgconfig/')
    search_dirs.append('/usr/lib/pkgconfig/')
    for dirname in search_dirs:
        for root, dirs, files in os.walk(dirname):
            for f in files:
                if f == target:
                    _tmp = _grep("\Version: ", os.path.join(root, target))
                    return _tmp.split()[1]


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

# find to header path
header_path = find_file('Magick++.h', search_include_dirs)
if not header_path:
    raise Exception("Magick++ not found")
print("include header path: %s" % header_path)
include_dirs.append(header_path)

# find to library path for boost_python
# TODO: only test on Ubuntu11.10
_version = sys.version_info

boost_lib_target_files = []
if _version >= (3, ):
    boost_lib_target_files.append("boost_python-py%s%s" % (_version[0], _version[1]))
boost_lib_target_files.append("boost_python-mt-py%s%s" % (_version[0], _version[1]))
#gentoo appends the python version numbers to the boost_python libraries
boost_lib_target_files.append("boost_python-%s.%s" % (_version[0], _version[1]))
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
    _version = get_version_from_pc(search_include_dirs, GMCPP_PC)
else:
    _version = get_version_from_pc(search_include_dirs, IMCPP_PC)
if not _version:
    _version = get_version_from_devheaders(include_dirs)
if _version:
    print("%s version: %s" % (LIBRARY, _version))
    _version = list(map(int, _version.split('.')))
    if len(_version) == 2:
        # ex) 1.2 -> 1.2.0
        _version.append(0)
    if LIBRARY == 'GraphicsMagick':
        if _version[0] == 1 and _version[1] == 3 and _version[2] >= 19:
            ext_compile_args = ["-DPGMAGICK_LIB_GRAPHICSMAGICK_1_3_6",
                                "-DPGMAGICK_LIB_GRAPHICSMAGICK_1_3_x",
                                "-DPGMAGICK_LIB_GRAPHICSMAGICK_1_3_19"]
        elif _version[0] == 1 and _version[1] == 3 and _version[2] >= 6:
            # for not Ubuntu10.04
            ext_compile_args = ["-DPGMAGICK_LIB_GRAPHICSMAGICK_1_3_6",
                                "-DPGMAGICK_LIB_GRAPHICSMAGICK_1_3_x"]
        elif not (_version[0] == 1 and _version[1] == 1):
            # for GM version 1.3.x and higher
            ext_compile_args = ["-DPGMAGICK_LIB_GRAPHICSMAGICK_1_3_x"]
    elif LIBRARY == 'ImageMagick':
        ext_compile_args = ["-DPGMAGICK_LIB_IMAGEMAGICK"]
else:
    _version = '%s version: ???' % (LIBRARY)

exec(open('pgmagick/_version.py').read())

setup(name='pgmagick',
      version=__version__,
      description="Yet Another Python wrapper for GraphicsMagick",
      long_description=open('README.rst').read(),
      author='Hideo Hattori',
      author_email='hhatto.jp@gmail.com',
      url='http://bitbucket.org/hhatto/pgmagick',
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
