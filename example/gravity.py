from pgmagick import Image, Geometry, Color, TypeMetric, \
                     DrawableText, DrawableList, DrawableGravity, GravityType

im = Image(Geometry(600, 600), Color("transparent"))

im.fontPointsize(30)
im.fillColor(Color("#f010f0"))
im.strokeColor(Color("transparent"))
im.font("Vera.ttf")
dl = DrawableList()

dl.append(DrawableGravity(GravityType.CenterGravity))
dl.append(DrawableText(0, 0, "center"))

tm = TypeMetric()
im.fontTypeMetrics("northn", tm)
font_height = tm.textHeight()
dl.append(DrawableGravity(GravityType.NorthGravity))
dl.append(DrawableText(0, font_height / 2., "north"))

dl.append(DrawableGravity(GravityType.WestGravity))
dl.append(DrawableText(0, 0, "west"))

dl.append(DrawableGravity(GravityType.EastGravity))
dl.append(DrawableText(0, 0, "east"))
dl.append(DrawableText(0, 20, "east-long"))

dl.append(DrawableGravity(GravityType.SouthGravity))
dl.append(DrawableText(0, 0, "south"))

dl.append(DrawableGravity(GravityType.NorthWestGravity))
dl.append(DrawableText(0, font_height / 2., "north-west"))

dl.append(DrawableGravity(GravityType.NorthEastGravity))
dl.append(DrawableText(0, font_height / 2., "north-east"))

dl.append(DrawableGravity(GravityType.SouthWestGravity))
dl.append(DrawableText(0, 0, "south-west"))

dl.append(DrawableGravity(GravityType.SouthEastGravity))
dl.append(DrawableText(0, 0, "south-east"))

im.draw(dl)
im.write("test.png")
