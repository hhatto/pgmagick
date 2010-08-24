import sys
from pgmagick import Image, FilterTypes as ft

# same
# convert SRC.jpg -filter Sinc -resize 500x500 -sharpen 1 -quality 100 DST.jpg
# gm convert SRC.jpg -filter Sinc -resize 500x500 -sharpen 1 -quality 100 DST.jpg

im = Image('./X.jpg')
im.quality(100)
im.sharpen(1.0)
im.write('./Y.jpg')

im = Image('./X.jpg')
im.quality(100)
im.filterType(ft.SincFilter)
im.scale('1000x1000')
im.sharpen(1.0)
im.write('./Y.jpg')

im = Image('./X.jpg')
im.quality(100)
im.filterType(ft.SincFilter)
im.scale('100x100')
im.sharpen(1.0)
im.write('./Y.jpg')

im = Image('./X.jpg')
im.quality(100)
im.filterType(ft.SincFilter)
im.scale('500x500')
im.sharpen(1.0)
im.write('./Y.jpg')
