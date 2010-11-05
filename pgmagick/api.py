import pgmagick


class Image(pgmagick.Image):

    height = 0
    width = 0

    def __init__(self, filename=None, color=None, *args, **kargs):
        if type(filename) == str:
            pgmagick.Image.__init__(self, filename)
        elif type(filename) == list or type(filename) == tuple:
            size = filename
            geometry = pgmagick.Geometry(int(size[0]), int(size[1]))
            if type(color) == list or type(color) == tuple:
                r, g, b = int(color[0]), int(color[1]), int(color[2])
                color = pgmagick.Color(r, g, b)
                pgmagick.Image.__init__(self, geometry, color)
            elif type(color) == str:
                if color.find('gradient') == 0:
                    pgmagick.Image.__init__(self, geometry, pgmagick.Color())
                    self.read(color)
                else:
                    color = pgmagick.Color(color)
                    pgmagick.Image.__init__(self, geometry, color)
            else:
                pgmagick.Image.__init__(self, geometry, pgmagick.Color())
        else:
            pgmagick.Image.__init__(self)
        self.width, self.height = self.columns(), self.rows()

    def annotate(self, string, position=(0, 0), gravity='center', angle=0):
        position = pgmagick.Geometry(int(position[0]), int(position[1]))
        exec "gravity_type = pgmagick.GravityType.%sGravity" % gravity.title()
        pgmagick.Image.annotate(self, string, position, gravity_type, angle)

    def draw(self, draw_obj):
        if type(draw_obj) == list or type(draw_obj) == tuple:
            draw = DrawableList()
            for d in draw_obj:
                draw.append(d)
        else:
            draw = draw_obj
        pgmagick.Image.draw(self, draw)

    def scale(self, size, filter_type=None):
        if type(size) == float:
            scaled_height = self.height * size
            scaled_width = self.width * size
            size = "%dx%d" % (int(scaled_width), int(scaled_height))
        elif type(size) == list or type(size) == tuple:
            scaled_width, scaled_height = int(size[0]), int(size[1])
            size = "%dx%d" % (int(scaled_width), int(scaled_height))
        if filter_type:
            filter_type = filter_type.title()
            exec "filter_type = pgmagick.FilterTypes.%sFilter" % filter_type
            pgmagick.Image.filterType(self, filter_type)
        geometry = pgmagick.Geometry(size)
        pgmagick.Image.scale(self, geometry)
        self.height = self.rows()
        self.width = self.columns()


class Draw(object):

    def __init__(self):
        self.drawer = pgmagick.DrawableList()

    def affine(self, sx, sy, rx, ry, tx, ty):
        affine = pgmagick.DrawableAffine(float(sx), float(sy),
                                         float(rx), float(ry),
                                         float(tx), float(ty))
        self.drawer.append(affine)

    def arc(self, start_x, start_y, end_x, end_y, start_degrees, end_degrees):
        arc = pgmagick.DrawableArc(float(start_x), float(start_y),
                                   float(end_x), float(end_y),
                                   float(start_degrees), float(end_degrees))
        self.drawer.append(arc)

    def bezier(self, points):
        """
        points -> ((5, 5), (6, 6), (7, 7))
        """
        coordinates = pgmagick.CoordinateList()
        for point in points:
            x, y = float(point[0]), float(point[1])
            coordinates.append(pgmagick.Coordinate(x, y))
        self.drawer.append(pgmagick.DrawableBezier(coordinates))
