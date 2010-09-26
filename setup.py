from setuptools import setup, find_packages, Extension
from distutils.sysconfig import get_python_inc
import glob
import os

include_dirs = [get_python_inc()]
library_dirs = []

search_include_dirs = ['/usr/local/include/GraphicsMagick',
                       '/usr/include/GraphicsMagick/']
search_library_dirs = ['/usr/local/lib/', '/usr/lib/']


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
    return False

include_dirs.append(find_file('Magick++', search_include_dirs))
library_dirs.append(find_file('libGraphicsMagick', search_library_dirs))

setup(name='pgmagick',
    version="0.2.3",
    description="Yet Another Python wrapper for GraphicsMagick",
    long_description=open('README.rst').read(),
    author='Hideo Hattori',
    author_email='hhatto.jp@gmail.com',
    license='MIT',
    platforms='Linux',
    packages=find_packages(),
    ext_modules=[
        Extension('pgmagick._pgmagick',
                  sources=glob.glob('./src/*.cpp'),
                  include_dirs=include_dirs,
                  library_dirs=library_dirs,
                  libraries=['boost_python', 'GraphicsMagick++'],
                 )],
    classifiers=[
        'Development Status :: 4 - Beta',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: MIT License',
        'Operating System :: POSIX :: Linux',
        'Programming Language :: C++',
        'Programming Language :: Python',
        'Topic :: Multimedia :: Graphics'],
)
