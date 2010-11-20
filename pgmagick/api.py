import pgmagick


def _convert_colorobj(input_obj):
    if isinstance(input_obj, (list, tuple)):
        r, g, b = int(input_obj[0]), int(input_obj[1]), int(input_obj[2])
        color = pgmagick.Color(r, g, b)
    elif isinstance(input_obj, str):
        color = pgmagick.Color(input_obj)
    else:
        color = input_obj
        assert isinstance(color, pgmagick.Color)
    return color


class Image(pgmagick.Image):

    height = 0
    width = 0

    def __init__(self, filename=None, color=None, *args, **kargs):
        if isinstance(filename, str):
            pgmagick.Image.__init__(self, filename)
        elif isinstance(filename, (list, tuple)):
            size = filename
            geometry = pgmagick.Geometry(int(size[0]), int(size[1]))
            if isinstance(color, (list, tuple)):
                r, g, b = int(color[0]), int(color[1]), int(color[2])
                color = pgmagick.Color(r, g, b)
                pgmagick.Image.__init__(self, geometry, color)
            elif isinstance(color, str):
                if color.find('gradient') == 0 or color.find('plasma') == 0:
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

    # API of Manipulate An Image
    def adaptive_threshold(self, width, height, offset=0):
        # TODO: not implemented
        pass

    def add_noise(self, noise_type):
        # TODO: not implemented
        pass

    def add_noise_channel(self, channel, noise_type):
        # TODO: not implemented
        pass

    def affine_transform(self, affine):
        # TODO: not implemented
        pass

    def annotate(self, string, position=(0, 0), gravity='center', angle=0):
        position = pgmagick.Geometry(int(position[0]), int(position[1]))
        exec "gravity = pgmagick.GravityType.%sGravity" % gravity.title()
        pgmagick.Image.annotate(self, string, position, gravity, angle)

    def blur(self, radius=0.0, sigma=1.0):
        # TODO: not implemented
        pass

    def blur_channel(self, channel, radius=0.0, sigma=1.0):
        # TODO: not implemented
        pass

    def border(self, geometry=None):
        # TODO: not implemented
        pass

    def channel(self, channel):
        # TODO: not implemented
        pass

    def channel_depth(self, channel, depth=None):
        # TODO: not implemented
        pass

    def charcoal(self, radius=0.0, sigma=1.0):
        # TODO: not implemented
        pass

    def chop(self, geometry):
        # TODO: not implemented
        pass

    def colorize(self, opacity_rgb, color):
        # TODO: not implemented
        pass

    def color_matrix(self, order, color_matrix):
        # TODO: not implemented
        pass

    def comment(self, comment):
        # TODO: not implemented
        pass

    def compare(self, reference):
        # TODO: not implemented
        pass

    def composite(self, composite_img, offset,
                  compose=pgmagick.CompositeOperator.InCompositeOp):
        if isinstance(offset, (list, tuple)):
            x = int(offset[0])
            y = int(offset[1])
            offset = pgmagick.Geometry(x, y)
        elif isinstance(offset, pgmagick.Geometry):
            pass
        elif isinstance(offset, str):   # is gravity (string)
            exec "offset = pgmagick.GravityType.%sGravity" % offset.title()
        else:   # is gravity (pgmagick.GravityType)
            pass
        if isinstance(compose, pgmagick.CompositeOperator):
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

    def contrast(self, sharpen):
        # TODO: not implemented
        pass

    def convolve(self, order, kernel):
        # TODO: not implemented
        pass

    def crop(self, geometry):
        # TODO: not implemented
        pass

    def cycle_colormap(self, amount):
        # TODO: not implemented
        pass

    def draw(self, draw_obj):
        if isinstance(draw_obj, (list, tuple)):
            draw = pgmagick.DrawableList()
            for d in draw_obj:
                draw.append(d)
        elif isinstance(draw_obj, Draw):
            draw = draw_obj.drawer
        else:
            draw = draw_obj
        pgmagick.Image.draw(self, draw)

    def edge(self, radius=0.0):
        # TODO: not implemented
        pass

    def emboss(self, radius=0.0, sigma=1.0):
        # TODO: not implemented
        pass

    def floodfill_color(self, point, fill_color):
        # TODO: not implemented
        pass

    def floodfill_opacity(self, point, opacity, method):
        # TODO: not implemented
        pass

    def floodfill_texture(self, point, texture):
        # TODO: not implemented
        pass

    def scale(self, size, filter_type=None):
        if isinstance(size, float):
            scaled_height = self.height * size
            scaled_width = self.width * size
            size = "%dx%d" % (int(scaled_width), int(scaled_height))
        elif isinstance(size, (list, tuple)):
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

    # API of Set/Get Image
    def font_pointsize(self, point_size=None):
        if point_size:
            point_size = float(point_size)
            pgmagick.Image.fontPointsize(self, point_size)
        else:
            return pgmagick.Image.fontPointsize(self)


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
        """Draw a Bezier-curve.

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
            paint_method = pm.FillToBorderMethod
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
        color = _convert_colorobj(color)
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

    def gravity(self, gravity_type):
        if isinstance(gravity_type, str):
            exec "g = pgmagick.GravityType.%sGravity" % gravity_type.title()
        else:
            g = gravity_type
        gravity_type = pgmagick.DrawableGravity(g)
        self.drawer.append(gravity_type)

    def line(self, start_x, start_y, end_x, end_y):
        line = pgmagick.DrawableLine(start_x, start_y, end_x, end_y)
        self.drawer.append(line)

    def matte(self, x, y, paint_method):
        # TODO: not implemented
        pass

    def miter_limit(self, miterlimit):
        # TODO: not implemented
        pass

    def path(self, vpath):
        # TODO: not implemented
        pass

    def point(self, x, y):
        # TODO: not implemented
        pass

    def pointsize(self, pointsize):
        pointsize = pgmagick.DrawablePointSize(pointsize)
        self.drawer.append(pointsize)

    def polygon(self, coordinates):
        # TODO: not implemented
        pass

    def polyline(self, coordinates):
        # TODO: not implemented
        pass

    def rectangle(self, upper_left, lower_right):
        # TODO: not implemented
        pass

    def rotation(self, angle):
        # TODO: not implemented
        pass

    def round_rectangle(self, center, size, corner_size):
        # TODO: not implemented
        pass

    def scaling(self, x, y):
        # TODO: not implemented
        pass

    def skewx(self, angle):
        # TODO: not implemented
        pass

    def skewy(self, angle):
        # TODO: not implemented
        pass

    def stroke_antialias(self, flag=True):
        """stroke antialias

        :param flag: True or False. (default is True)
        :type flag: bool
        """
        antialias = pgmagick.DrawableStrokeAntialias(flag)
        self.drawer.append(antialias)

    def stroke_color(self, color):
        color = _convert_colorobj(color)
        color = pgmagick.DrawableStrokeColor(color)
        self.drawer.append(color)

    def stroke_linecap(self, linecap):
        """set to stroke linecap.

        :param linecap: 'undefined', 'butt', 'round', 'square'
        :type linecap: str
        """
        exec "linecap = pgmagick.LineCap.%sCap" % linecap.title()
        linecap = pgmagick.DrawableStrokeLineCap(linecap)
        self.drawer.append(linecap)

    def stroke_linejoin(self, linejoin):
        """set to stroke linejoin.

        :param linejoin: 'undefined', 'miter', 'round', 'bevel'
        :type linejoin: str
        """
        exec "linejoin = pgmagick.LineJoin.%sJoin" % linejoin.title()
        linejoin = pgmagick.DrawableStrokeLineJoin(linejoin)
        self.drawer.append(linejoin)

    def stroke_width(self, width):
        width = float(width)
        width = pgmagick.DrawableStrokeWidth(width)
        self.drawer.append(width)

    def text(self, x, y, string, encoding=None):
        # TODO: unable encoding
        text = pgmagick.DrawableText(x, y, string)
        self.drawer.append(text)

    def text_antialias(self, flag=True):
        """text antialias

        :param flag: True or False. (default is True)
        :type flag: bool
        """
        antialias = pgmagick.DrawableTextAntialias(flag)
        self.drawer.append(antialias)

    def text_decoration(self, decoration):
        """text decoration

        :param decoration: 'no', 'underline', 'overline', 'linethrough'
        :type decoration: str
        """
        if decoration.lower() == 'linethrough':
            d = pgmagick.DecorationType.LineThroughDecoration
        else:
            decoration_type_string = "%sDecoration" % decoration.title()
            exec "d = pgmagick.DecorationType.%s" % decoration_type_string
        decoration = pgmagick.DrawableTextDecoration(d)
        self.drawer.append(decoration)

    def text_undercolor(self, color):
        color = _convert_colorobj(color)
        undercolor = pgmagick.DrawableTextUnderColor(color)
        self.drawer.append(undercolor)

    def translate(self, x, y):
        self.drawer.append(pgmagick.DrawableTranslation(float(x), float(y)))
