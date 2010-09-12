from pgmagick import Image, Geometry, Color, Coordinate, CoordinateList, \
                     DrawableBezier

im = Image(Geometry(300, 200), Color("white"))
cdl = CoordinateList()
cdl.append(Coordinate(20, 20))
cdl.append(Coordinate(100, 50))
cdl.append(Coordinate(50, 100))
cdl.append(Coordinate(160, 160))
db = DrawableBezier(cdl)
im.draw(db)
im.display()
