import sys
sys.path.append('../')
sys.path.append('./')
from pgmagick.api import Image

im = Image()
im = Image((600, 400), 'red')
im = Image((600.5, 400.4), 'red')
assert im.height == 400
assert im.width == 600
im.scale(0.6)
im.write('t.jpg')
