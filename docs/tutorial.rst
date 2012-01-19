========
Tutorial
========

Installation
============

.. code-block:: bash

    $ easy_install -ZU pgmagick

or

.. code-block:: bash

    $ pip install --upgrade pgmagick


Requirements
------------
pgmagick is available on UNIX-like systems. and depend on the following libraries.

- `GraphicsMagick(Magick++)`_ : graphing library. 1.3.5 and higher version.
- `Boost.Python`_ : wrap C++ code. 1.40 and higher version.

.. _`GraphicsMagick(Magick++)`: http://www.graphicsmagick.org/Magick++/
.. _`Boost.Python`: http://www.boost.org/doc/libs/1_44_0/libs/python/doc/index.html

Ubuntu11.10
^^^^^^^^^^^
package support on Ubuntu11.10.

.. code-block:: bash

    $ apt-get install python-pgmagick

Ubuntu10.04+
^^^^^^^^^^^^

.. code-block:: bash

    $ apt-get install libgraphicsmagick++1-dev
    $ apt-get install libboost-python1.40-dev

Fedora
^^^^^^

.. code-block:: bash

    $ yum install GraphicsMagick-c++-devel
    $ yum install boost-devel

Debian
^^^^^^

.. code-block:: bash

    $ apt-get install libboost-python-dev
    $ apt-get install libgraphicsmagick++1-dev

GraphicsMagick from source package
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block:: bash

    $ ./configure --enable-shared=yes
    $ make && make install

