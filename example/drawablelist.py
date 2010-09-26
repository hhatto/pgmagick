from pgmagick import Image, DrawableCircle, DrawableText, \
                     DrawableList, Geometry, Color

im = Image(Geometry(300, 300), Color("yellow"))

circle = DrawableCircle(100.0, 100.0, 20.0, 20.0)

im.fontPointsize(65)
im.font("/var/lib/defoma/x-ttcidfont-conf.d/dirs/TrueType/UnBatang.ttf")
text = DrawableText(30, 250, "hello gm")
drawlist = DrawableList()
drawlist.append(circle)
drawlist.append(text)
im.draw(drawlist)

im.write('hoge.png')
