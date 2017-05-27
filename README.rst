About
=====

.. image:: https://travis-ci.org/hhatto/pgmagick.svg?branch=master
    :target: https://travis-ci.org/hhatto/pgmagick
    :alt: Build status

pgmagick is a yet another boost.python based wrapper for GraphicsMagick.


Installation
============
install to::

    $ pip install pgmagick


Requirements
============
Python2.5++, GraphicsMagick and Boost.Python.

package install on Ubuntu(test on Ubuntu10.04+)::

    ### Ubuntu11.10+ ###
    $ apt-get install python-pgmagick

    ### Ubuntu10.04+ ###
    $ apt-get install libgraphicsmagick++1-dev
    $ apt-get install libboost-python1.40-dev

package install on Fedora::

    $ yum install GraphicsMagick-c++-devel
    $ yum install boost-devel

GraphicsMagick from source package::

    $ ./configure --enable-shared=yes
    $ make && make install

MacOSX
------

via homebrew-cask(homebrew-pgmagick) with Python2
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
use `homebrew-pgmagick`_ ::

    $ brew tap hhatto/pgmagick
    $ brew install pgmagick

.. _`homebrew-pgmagick`: https://github.com/hhatto/homebrew-pgmagick

via homebrew-cask(homebrew-pgmagick) with Python3
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
with `--with-python3` option::

    $ brew install pgmagick --with-python3

via homebrew and pip with Python3
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
on MacOSX 10.11.6::

    $ brew install graphicsmagick
    $ brew install boost-python --with-python3
    $ pip install pgmagick

via homebrew and pip with Python2
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*update 2017.05.17*
on MacOSX 10.11.6::

    $ brew install graphicsmagick
    $ brew install boost-python
    $ pip install pgmagick

*update 2014.05.12*
on MacOSX 10.9.2 (add ARCHFLAGS)::

    $ brew install graphicsmagick
    $ brew install boost --with-python
    $ ARCHFLAGS=-Wno-error=unused-command-line-argument-hard-error-in-future pip install pgmagick


Windows
-------
Now, not official support.
However, *unofficial* binary packages exists.

- http://www.lfd.uci.edu/~gohlke/pythonlibs/#pgmagick

ImageMagick support
-------------------
pgmagick is supported to ImageMagick library. (*version:0.4+*)

package install on Ubuntu(test on Ubuntu10.04+)::

    $ apt-get install libmagick++-dev

show library name and version::

    >>> from pgmagick import gminfo
    >>> gminfo.library
    'GraphicsMagick'    # or 'ImageMagick'
    >>> gminfo.version
    '1.3.x'
    >>>

Usage
=====

scale example::

    >>> from pgmagick import Image
    >>> im = Image('input.jpg')
    >>> im.quality(100)
    >>> im.scale('100x100')
    >>> im.sharpen(1.0)
    >>> im.write('output.jpg')

resize example::

    >>> from pgmagick import Image
    >>> im = Image('input.jpg')
    >>> im.filterType(FilterTypes.SincFilter)
    >>> im.resize('100x100')
    >>> im.write('output.jpg')

composite example::

    >>> from pgmagick import Image, CompositeOperator as co
    >>> base = Image('base.png')
    >>> layer = Image('layer_one.png')
    >>> base.composite(layer, 100, 100, co.OverCompositeOp)
    >>> im.write('output.png')

draw example::

    >>> from pgmagick import Image, DrawableCircle, DrawableText, Geometry, Color
    >>> im = Image(Geometry(300, 300), Color("yellow"))
    >>> circle = DrawableCircle(100, 100, 20, 20)
    >>> im.draw(circle)
    >>> im.fontPointsize(65)
    >>> text = DrawableText(30, 250, "Hello pgmagick")
    >>> im.draw(text)
    >>> im.write('hoge.png')

blob access::

    >>> from pgmagick import Image, Blob, Geometry
    >>> blob = Blob(open('filename.jpg').read())
    >>> blob.update(open('filename2.jpg').read())
    >>> img = Image(blob, Geometry(600, 480))
    >>> img.scale('300x200')
    >>> img.write('out.jpg')

create animated-GIF::

    from pgmagick import Image, ImageList, Geometry, Color

    imgs = ImageList()
    for color in ('red', 'blue', 'green', 'black', 'yellow'):
        imgs.append(Image(Geometry(200, 200), Color(color)))
    imgs.animationDelayImages(100)
    imgs.scaleImages(Geometry(100, 100))
    imgs.writeImages('output.gif')

more API detail... read to `Magick++ API for GraphicsMagick`_ document.

.. _`Magick++ API for GraphicsMagick`: http://www.graphicsmagick.org/Magick++/

Python APIs(*NOTICE!! this api is alpha version!!*)::

    >>> from pgmagick.api import Image
    >>> img = Image((300, 300), "gradient:#ffffff-#000000")
    >>> img.scale(0.8)
    >>> img.write('out.png')


Links
=====
* PyPI_
* `Project Page`_
* `Project Page (Old)`_

.. _PyPI: http://pypi.python.org/pypi/pgmagick/
.. _`Project Page`: https://github.com/hhatto/pgmagick/
.. _`Project Page (Old)`: https://bitbucket.org/hhatto/pgmagick/
