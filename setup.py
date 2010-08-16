from setuptools import setup, find_packages, Extension

include_dirs = ['/usr/include/python2.6',
                '/usr/include/GraphicsMagick/']
library_dirs = ['/usr/lib']

setup(name='pgmagick',
    version="0.0.3",
    description="Yet Another Python wrapper for GraphicsMagick++",
    long_description=open('README.rst').read(),
    author='Hideo Hattori',
    author_email='hhatto.jp@gmail.com',
    license='MIT',
    platforms='Linux',
    packages=find_packages(),
    ext_modules=[
        Extension('pgmagick._pgmagick',
                  sources=['src/_Blob.cpp',
                           'src/_Color.cpp',
                           'src/_Exception.cpp',
                           'src/_FilterTypes.cpp',
                           'src/_Geometry.cpp',
                           'src/_Image.cpp',
                           'src/_Montage.cpp',
                           'src/_main.cpp'],
                  include_dirs=include_dirs,
                  library_dirs=library_dirs,
                  libraries=['boost_python', 'GraphicsMagick++'],
                 )],
    classifiers=[
        'Development Status :: 3 - Alpha',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: MIT License',
        'Operating System :: POSIX :: Linux',
        'Programming Language :: C++',
        'Programming Language :: Python',
        'Topic :: Multimedia :: Graphics'],
)
