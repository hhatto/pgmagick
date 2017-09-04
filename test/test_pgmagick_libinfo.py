from __future__ import print_function

from pgmagick import gminfo as info

libinfo = info()
print(libinfo.version)
print(libinfo.library)
