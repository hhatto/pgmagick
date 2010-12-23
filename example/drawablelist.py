from pgmagick import Image, Geometry, Color, \
                     DrawableAffine, DrawableCircle, DrawableCompositeImage, \
                     DrawableText, DrawableList

im = Image(Geometry(300, 300), Color("yellow"))
circle = DrawableCircle(100.0, 100.0, 20.0, 20.0)
im.fontPointsize(65)
im.font("/var/lib/defoma/x-ttcidfont-conf.d/dirs/TrueType/UnBatang.ttf")
text = DrawableText(30, 250, "hello gm")
drawlist = DrawableList()
drawlist.append(circle)
drawlist.append(text)
im.draw(drawlist)
im.write('non-affine.png')

im = Image(Geometry(300, 300), Color("yellow"))
circle = DrawableCircle(100.0, 100.0, 20.0, 20.0)
im.fontPointsize(65)
im.font("/var/lib/defoma/x-ttcidfont-conf.d/dirs/TrueType/UnBatang.ttf")
text = DrawableText(30, 250, "hello gm")
drawlist = DrawableList()
drawlist.append(DrawableAffine(0.9, 0.9, 0.1, 0.1, 0.5, 0.5))
drawlist.append(circle)
drawlist.append(text)
im.draw(drawlist)
im.write('affine.png')


im = Image(Geometry(300, 300), Color("yellow"))
d = DrawableCompositeImage(100, 150, im)
im.draw(d)
im.write('ttt.png')
