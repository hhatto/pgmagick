About
=====
pgmagick is a yet another boost.python based wrapper for GraphicsMagick.
(PythonMagick_ is dead?)

.. _PythonMagick: http://pypi.python.org/pypi/PythonMagick/

Install
=======

    $ pip install pgmagick

Usage
=====

example:

    >>> from pgmagick import Image, FilterTypes
    >>> im = Image('input.jpg')
    >>> im.quality(100)
    >>> im.filterType(FilterTypes.SincFilter)
    >>> im.scale('100x100')
    >>> im.sharpen(1.0)
    >>> im.write('output.jpg')

