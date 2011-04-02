About
=====
pgmagick is a yet another boost.python based wrapper for GraphicsMagick.
(PythonMagick_ is dead?)

.. _PythonMagick: http://pypi.python.org/pypi/PythonMagick/


Install
=======
install to::

    $ pip install pgmagick


Require
=======
GraphicsMagick and Boost.Python.

package install on Ubuntu(test on Ubuntu10.04+)::

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
install reported on MacOSX, Thanks Simon Harrison.

http://simonharrison.info/talk/mac-os/pgmagick-on-mac-os/


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

more API detail... read to `Magick++ API for GraphicsMagick`_ document.

.. _`Magick++ API for GraphicsMagick`: http://www.graphicsmagick.org/Magick++/

Python APIs(*NOTICE!! this api is alpha version!!*)::

    >>> from pgmagick.api import Image
    >>> img = Image((300, 300), "gradient:#ffffff-#000000")
    >>> img.scale(0.8)
    >>> img.write('out.png')

