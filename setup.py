from setuptools import setup, find_packages, Extension
from distutils.sysconfig import get_python_inc
import glob

include_dirs = [get_python_inc(),
                '/usr/include/GraphicsMagick/']
library_dirs = ['/usr/lib']

setup(name='pgmagick',
    version="0.2.0",
    description="Yet Another Python wrapper for GraphicsMagick++",
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
