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

    def composite(self, composite_img, offset,
                  compose=pgmagick.CompositeOperator.InCompositeOp):
        if type(offset) == list or type(offset) == tuple:
            x = int(offset[0])
            y = int(offset[1])
            offset = pgmagick.Geometry(x, y)
        elif pgmagick.Geometry == type(offset):
            pass
        elif type(offset) == str:   # is gravity (string)
            exec "offset = pgmagick.GravityType.%sGravity" % offset.title()
        else:   # is gravity (pgmagick.GravityType)
            pass
        if type(compose) == pgmagick.CompositeOperator:
            pass
        elif compose.lower() in ('copyblue', 'copygreen', 'copyopacity',
                                 'copyred', 'copycyan', 'copymagenta',
                                 'copyyellow', 'copyblack'):
            color = compose.lower().split('copy')[1].title()
            exec "compose = pgmagick.CompositeOperator."\
                 "Copy%sCompositeOp" % color
        else:   # other string
            exec "compose = pgmagick.CompositeOperator."\
                 "%sCompositeOp" % compose.title()
        pgmagick.Image.composite(self, composite_img, offset, compose)

    def draw(self, draw_obj):
        if type(draw_obj) == list or type(draw_obj) == tuple:
            draw = DrawableList()
            for d in draw_obj:
                draw.append(d)
        elif type(draw_obj) == Draw:
            draw = draw_obj.drawer
        else:
            draw = draw_obj
        pgmagick.Image.draw(self, draw)

    def font_pointsize(self, point_size=None):
        if point_size:
            point_size = float(point_size)
            pgmagick.Image.fontPointsize(self, point_size)
        else:
            return pgmagick.Image.fontPointsize(self)

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
        Draw a Bezier-curve.

        :param points: ex.) ((5, 5), (6, 6), (7, 7))
        :type points: list
        """
        coordinates = pgmagick.CoordinateList()
        for point in points:
            x, y = float(point[0]), float(point[1])
            coordinates.append(pgmagick.Coordinate(x, y))
        self.drawer.append(pgmagick.DrawableBezier(coordinates))

    def circle(self, origin_x, origin_y, perim_x, perim_y):
        circle = pgmagick.DrawableCircle(float(origin_x), float(origin_y),
                                         float(perim_x), float(perim_y))
        self.drawer.append(circle)

    def color(self, x, y, paint_method):
        """
        :param paint_method: 'point' or 'replace' or 'floodfill' or
                             'filltoborder' or 'reset'
        """
        pm = pgmagick.PaintMethod()
        if paint_method.lower() == 'filltoborder':
            exec 'paint_method = pm.FillToBorder'
        else:
            exec 'paint_method = pm.%sMethod' % paint_method.title()
        color = pgmagick.DrawableColor(x, y, paint_method)
        self.drawer.append(color)

    def composite(self):
        # TODO: not implemented
        pass

    def ellipse(self, org_x, org_y, radius_x, radius_y, arc_start, arc_end):
        """
        :param org_x: origination x axis
        :param org_y: origination y axis
        :param radius_x: radius x axis
        :param radius_y: radius y axis
        :param arc_start: arc start angle
        :param arc_end: arc end angle
        """
        ellipse = pgmagick.DrawableEllipse(float(org_x), float(org_y),
                                           float(radius_x), float(radius_y),
                                           float(arc_start), float(arc_end))
        self.drawer.append(ellipse)

    def fill_color(self, color):
        if type(color) == list or type(color) == tuple:
            r, g, b = int(color[0]), int(color[1]), int(color[2])
            color = pgmagick.Color(r, g, b)
        else:   # type is str, or the other type
            color = pgmagick.Color(color)
        fill_color = pgmagick.DrawableFillColor(color)
        self.drawer.append(fill_color)

    def fill_rule(self, rule='evenodd'):
        if rule.lower() == 'evenodd':
            fill_rule = pgmagick.FillRule.EvenOddRule
        elif rule.lower() == 'nonzero':
            fill_rule = pgmagick.FillRule.NonZeroRule
        else:
            fill_rule = rule
        fill_rule = pgmagick.DrawableFillRule(fill_rule)
        self.drawer.append(fill_rule)

    def fill_opacity(self, opacity):
        """
        :param opacity: 0.0 <= opacity <= 1.0
        """
        opacity = pgmagick.DrawableFillOpacity(float(opacity))
        self.drawer.append(opacity)

    def font(self, family, style='normal', weight=400, stretch='normal'):
        exec "style = pgmagick.StyleType.%sStyle" % style.title()
        stretch = stretch.lower()
        if 'condensed' in stretch:
            tmp = stretch.split('condensed')[0]
            stretch = "%sCondensedStretch" % tmp.title()
        elif 'expanded' in stretch:
            tmp = stretch.split('expanded')[0]
            stretch = "%sExpandedStretch" % tmp.title()
        else:
            stretch = "%sStretch" % stretch.title()
        exec "stretch = pgmagick.StretchType.%s" % stretch
        if weight is 'bold':
            weight = 800
        font = pgmagick.DrawableFont(family, style, weight, stretch)
        self.drawer.append(font)

    def pointsize(self, pointsize):
        pointsize = pgmagick.DrawablePointSize(pointsize)
        self.drawer.append(pointsize)

    def text(self, x, y, string, encoding=None):
        # TODO: unable encoding
        text = pgmagick.DrawableText(x, y, string)
        self.drawer.append(text)
