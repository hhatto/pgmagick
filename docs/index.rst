.. pgmagick documentation master file, created by
   sphinx-quickstart on Sat Nov 12 15:58:03 2011.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Welcome to pgmagick
====================================

pgmagick is a `GraphicsMagick(Magick++)`_ binding for Python.

.. _`GraphicsMagick(Magick++)`: http://www.graphicsmagick.org/Magick++/


Example
=======
example of resizing JPEG image.

.. code-block:: python

    from pgmagick import Image

    img = Image('input.jpg')
    img.quality(80)
    img.scale('20%')
    img.write('output.jpg')

User's Guide
============

.. toctree::
   :maxdepth: 2

   tutorial
   cookbook
   api


Community
=========
There is mailinglist for discussion about pgmagick hosted on librelist_.

To subscribe, send a mail to pgmagick@librelist.com and reply to
the confirmation mail.

`[pgmagick] archives`_

.. _librelist: http://librelist.com/
.. _`[pgmagick] archives`: http://librelist.com/browser/pgmagick/

Development
===========
pgmagick is written by `Hideo Hattori`_.
contact the author by e-mail to hhatto.jp@gmail.com

- `Source Code (on bitbucket)`_
- `Issue Tracker (on bitbucket)`_

.. _`Hideo Hattori`: http://www.hexacosa.net/
.. _`Source Code (on bitbucket)`: https://bitbucket.org/hhatto/pgmagick/src
.. _`Issue Tracker (on bitbucket)`: https://bitbucket.org/hhatto/pgmagick/issues


License
=======
pgmagick is under the MIT License. see the `LICENSE file`_.

.. _`LICENSE file`: https://bitbucket.org/hhatto/pgmagick/src/tip/LICENSE

