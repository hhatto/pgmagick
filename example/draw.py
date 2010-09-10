from pgmagick import Image, Drawable, DrawableCircle, DrawableText, \
                     Geometry, Color

im = Image(Geometry(300, 300), Color("yellow"))

circle = DrawableCircle(100.0, 100.0, 20.0, 20.0)
circle = Drawable(circle)
im.draw(circle)

im.fontPointsize(65)
im.font("/var/lib/defoma/x-ttcidfont-conf.d/dirs/TrueType/UnBatang.ttf")
text = DrawableText(30, 250, "hello gm")
text = Drawable(text)
im.draw(text)

im.write('hoge.png')
