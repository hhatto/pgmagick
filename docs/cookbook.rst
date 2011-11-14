:tocdepth: 2

Cookbook
=================

.. .. contents::


creating a color of red background JPEG image
---------------------------------------------

.. code-block:: python

    from pgmagick.api import Image

    img = Image((300, 200), 'red')
    img.write('bg-red.jpg')

.. image:: _images/bg-red.jpg


creating a transparency PNG image
---------------------------------

.. code-block:: python

    from pgmagick.api import Image

    img = Image((300, 200), 'transparent')
    img.write('transparent.png')

.. image:: _images/transparent.png


creating a gradient image
-------------------------

.. code-block:: python

    from pgmagick.api import Image

    img = Image((300, 200), 'gradient:#ffffff-#000000')
    img.write('gradient.png')

.. image:: _images/gradient.png


draw text
-----------

.. code-block:: python

    from pgmagick.api import Image

    img = Image((300, 200))
    img.annotate('Hello World')
    img.write('helloworld.png')

.. image:: _images/helloworld.png


斜め45度に傾いた文字を描く
draw text of rotated 45 degrees
-------------------------------

.. code-block:: python

    from pgmagick.api import Image

    img = Image((300, 200))
    img.annotate('Hello World', angle=45)
    img.write('helloworld45.png')

.. image:: _images/helloworld45.png


draw text of 2byte code
-----------------------

.. code-block:: python

    # coding: utf-8
    from pgmagick.api import Image

    img = Image((300, 200))
    img.font("/usr/share/fonts/truetype/ttf-japanese-gothic.ttf")
    img.annotate('Hello World')
    img.annotate('ようこそpgmagickへ!!')
    img.write('japanese-text.png')

.. image:: _images/japanese-text.png


scaling a image
---------------

.. code-block:: python

    from pgmagick.api import Image

    img = Image('gradient.png')
    img.scale(0.5)
    img.write('halfscale.png')

.. image:: _images/halfscale.png

.. code-block:: python

    from pgmagick.api import Image

    img = Image('gradient.png')
    img.scale((150, 100), 'lanczos')
    img.write('halfscale2.png')

.. image:: _images/halfscale2.png


scaling a JPEG image
-----------------------

.. code-block:: python

    from pgmagick import Image, Blob

    img = Image(Blob(open('lena_std.jpg').read()), Geometry(200, 200))
    img.scale('200x200')
    img.write('lena_scale.jpg')

.. image:: _images/lena_std.jpg
.. image:: _images/lena_scale.jpg



get image size
----------------

.. code-block:: python

    from pgmagick.api import Image

    img = Image((300, 200))
    print img.columns(), img.rows()
    print img.width, img.height


.. code-block:: bash

    $ python size.py
    300 200
    300 200


..    画像を半透明にする
..    ------------------
..
..    .. code-block:: python
..
..        from pgmagick.api import Image
..
..        img = Image('lena.jpg')
..        img.opacity(80)
..        img.write('lena_opacity80.jpg')
..
..    .. image:: _images/lena.jpg
..    .. image:: _images/lena_opacity80.png


sharpen filtering
----------------------

.. code-block:: python

    from pgmagick.api import Image

    img = Image('lena.jpg')
    img.sharpen(1)
    img.write('lena_sharpen1.jpg')

.. image:: _images/lena.jpg
.. image:: _images/lena_sharpen1.jpg


blur filtering
--------------

.. code-block:: python

    from pgmagick.api import Image

    img = Image('lena.jpg')
    img.blur(10, 5)
    img.write('lena_blur.jpg')

.. image:: _images/lena.jpg
.. image:: _images/lena_blur.jpg


Edge extraction
---------------

.. code-block:: python

    from pgmagick.api import Image

    img = Image('lena.jpg')
    img.edge(2)
    img.write('lena_edge.jpg')

.. image:: _images/lena.jpg
.. image:: _images/lena_edge.jpg


removing a EXIF information
---------------------------

.. code-block:: python

    import sys
    from pgmagick import Image, Blob

    blob = Blob()
    img = Image('exif-sample.jpg')
    img.profile("*", blob)
    img.write('exif-strip.jpg')

.. image:: _images/exif-sample.jpg
    :width: 300px
.. image:: _images/exif-strip.jpg
    :width: 300px
