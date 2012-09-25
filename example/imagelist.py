from pgmagick import Image, ImageList, Geometry, Color

imgs = ImageList()
for color in ('red', 'blue', 'green', 'black', 'yellow'):
    imgs.append(Image(Geometry(200, 200), Color(color)))
imgs.animationDelayImages(100)
imgs.scaleImages(Geometry(100, 100))
print len(imgs)
imgs.writeImages('output.gif')

imgs = ImageList()
imgs.readImages('output.gif')
for img in imgs:
    print img
