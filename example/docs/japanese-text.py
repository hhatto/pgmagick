# coding: utf-8
from pgmagick.api import Image

img = Image((300, 200))
img.font("/etc/alternatives/fonts-japanese-gothic.ttf")
img.annotate('Hello World')
img.annotate('ようこそpgmagickへ!!')
img.write('japanese-text.png')
