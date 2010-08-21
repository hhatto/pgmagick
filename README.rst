About
=====
pgmagick is a yet another boost.python based wrapper for GraphicsMagick.
(PythonMagick_ is dead?)

.. _PythonMagick: http://pypi.python.org/pypi/PythonMagick/


Install
=======

    $ pip install pgmagick


Require
=======
GraphicsMagick and Boost.Python.

package install on Ubuntu::

    $ apt-get install libgraphicsmagick++-dev
    $ apt-get install libboost-python1.40-dev

package install on Fedora::

    $ yum install GraphicsMagick-c++-devel
    $ yum install boost-devel


Usage
=====

scale example::

    >>> from pgmagick import Image, FilterTypes
    >>> im = Image('input.jpg')
    >>> im.quality(100)
    >>> im.filterType(FilterTypes.SincFilter)
    >>> im.scale('100x100')
    >>> im.sharpen(1.0)
    >>> im.write('output.jpg')

composite example::

    >>> from pgmagick import Image, CompositeOperator as co
    >>> base = Image('base.png')
    >>> layer = Image('layer_one.png')
    >>> base.composite(layer, 100, 100, co.OverCompositeOp)
    >>> im.write('output.png')

more API detail... read to `Magick++ API for GraphicsMagick`_ document.

.. _`Magick++ API for GraphicsMagick`: http://www.graphicsmagick.org/Magick++/
