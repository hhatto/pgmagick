#!/usr/bin/env python
"""
usage:
    $ cd pgmagick/pgmagick
    $ python create_initpy.py > __init__.py
"""
import sys
sys.path.append('.')
import _pgmagick

print "import _pgmagick\n\n"
for obj in dir(_pgmagick):
    if obj[:2] is '__':
        continue
    if obj is 'DrawableBase':
        continue
    exec "typestr = str(type(_pgmagick.%s))" % obj
    if typestr == "<type 'Boost.Python.class'>":
        print "class %s(_pgmagick.%s):\n    pass\n" % (obj, obj)
    elif typestr == "<type 'type'>":
        print "%s = _pgmagick.%s\n" % (obj, obj)
