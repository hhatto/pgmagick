About
=====
pgmagick is a yet another boost.python based wrapper for GraphicsMagick.


Install
=======
install to::

    $ pip install pgmagick


Require
=======
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
install reported on MacOSX, Thanks Rohan Singh and Simon Harrison.

- http://rohanradio.com/blog/2011/12/02/installing-pgmagick-on-os-x/
- http://simonharrison.info/talk/2011/01/17/pgmagick-on-mac-os/ (old)

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

