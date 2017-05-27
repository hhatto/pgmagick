from pgmagick import Image, FilterTypes
im = Image('X.jpg')
im.filterType(FilterTypes.SincFilter)
im.resize('100x100')
im.write('output.jpg')
