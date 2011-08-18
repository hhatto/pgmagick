from pgmagick import Image, ImageList, Geometry, Color

imgs = ImageList()
for color in ('red', 'blue', 'green', 'black', 'yellow'):
    imgs.append(Image(Geometry(200, 200), Color(color)))
imgs.animationDelayImage(100)
imgs.scaleImage(Geometry(100, 100))
print len(imgs)
imgs.writeImages('output.gif')
