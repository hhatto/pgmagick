import pgmagick
pgmagick.__init()


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
        size = pgmagick.Image.size(self)
        self.width, self.height = size.width(), size.height()

    def annotate(self, string, position=(0, 0), gravity='center', angle=0):
        position = pgmagick.Geometry(int(position[0]), int(position[1]))
        exec "gravity_type = pgmagick.GravityType.%sGravity" % gravity.title()
        pgmagick.Image.annotate(self, string, position, gravity_type, angle)

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
        size = self.size()
        self.height = size.height()
        self.width = size.width()
