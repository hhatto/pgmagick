from setuptools import setup, find_packages, Extension
from distutils.sysconfig import get_python_inc
import glob
import os
import re

GMCPP_PC = 'GraphicsMagick++.pc'
include_dirs = [get_python_inc()]
library_dirs = []

search_include_dirs = ['/usr/local/include/GraphicsMagick',
                       '/usr/include/GraphicsMagick/']
search_library_dirs = ['/usr/local/lib64/', '/usr/lib64/',
                       '/usr/local/lib/', '/usr/lib/']


def _grep(regex, filename):
    for line in open(filename):
        if re.search(regex, line):
            return line


def get_gmversion_from_devheaders(search_dirs):
    target_api_name = "addNoiseChannel"
    for dirname in search_dirs:
        for root, dirs, files in os.walk(dirname):
            for f in files:
                if f == 'Image.h':
                    _tmp = _grep(target_api_name, dirname + 'Magick++/Image.h')
                    return '1.1.x'


def get_gmversion_from_pc(search_dirs):
    """similar to 'pkg-config --modversion GraphicsMagick++'"""
    search_dirs.append('/usr/local/lib/pkgconfig/')
    search_dirs.append('/usr/lib/pkgconfig/')
    for dirname in search_dirs:
        for root, dirs, files in os.walk(dirname):
            for f in files:
                if f == GMCPP_PC:
                    _tmp = _grep("\Version: ", dirname + GMCPP_PC)
                    return _tmp.split()[1]


def find_file(filename, search_dirs):
    for dirname in search_dirs:
        for root, dirs, files in os.walk(dirname):
            for f in files:
                if filename in f:
                    return dirname
            for d in dirs:
                if filename in d:
                    return dirname
            if filename in root:
                return dirname
    raise Exception(filename + " not found")

include_dirs.append(find_file('Magick++', search_include_dirs))
library_dirs.append(find_file('libGraphicsMagick', search_library_dirs))

ext_compile_args = []
gm_version = get_gmversion_from_pc(search_include_dirs)
if not gm_version:
    gm_version = get_gmversion_from_devheaders(include_dirs)
if gm_version:
    gm_version = gm_version.split('.')
    if gm_version[0] == str(1) and gm_version[1] == str(1):    # version 1.1.x
        ext_compile_args = ["-DGM_1_1_x"]
    print "GraphicsMagick++ version: %s.%s.%s" % (gm_version[0],
                                                  gm_version[1],
                                                  gm_version[2])

setup(name='pgmagick',
    version="0.3.3",
    description="Yet Another Python wrapper for GraphicsMagick",
    long_description=open('README.rst').read(),
    author='Hideo Hattori',
    author_email='hhatto.jp@gmail.com',
    url='http://bitbucket.org/hhatto/pgmagick',
    license='MIT',
    platforms='Linux',
    packages=find_packages(),
    ext_modules=[
        Extension('pgmagick._pgmagick',
                  sources=glob.glob('./src/*.cpp'),
                  include_dirs=include_dirs,
                  library_dirs=library_dirs,
                  libraries=['boost_python', 'GraphicsMagick++'],
                  extra_compile_args=ext_compile_args,
                 )],
    classifiers=[
        'Development Status :: 4 - Beta',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: MIT License',
        'Operating System :: POSIX :: Linux',
        'Programming Language :: C++',
        'Programming Language :: Python',
        'Topic :: Multimedia :: Graphics'],
    keywords="GraphicsMagick graphics visualize boost image",
)
