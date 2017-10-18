from __future__ import print_function

import hashlib
import sys
import unittest
import pgmagick
from pgmagick.api import Image, Draw


print(pgmagick.gminfo().version)
LIBGM_VERSION = [int(v) for v in pgmagick.gminfo().version.split('.')]


class ImageTestCase(unittest.TestCase):

    def setUp(self):
        self.img = Image((600, 400), 'red')

    def test_unicodefilename(self):
        self.img.write('unicode.png')
        img = Image(u'unicode.png')
        img.scale(0.5)
        img.write(u'unicode.jpg')

    def test_nonarg(self):
        Image()

    def test_arg(self):
        Image((600, 400), 'red')

    def test_arg_float(self):
        Image((600.5, 400.4), 'red')

    def test_blur(self):
        self.img.blur(2, 2.3)
        self.img.write('t.jpg')

    def test_blur_channel(self):
        self.img.blur_channel('cyan')
        self.img.write('t.jpg')

    def test_scale(self):
        img = Image((600, 400), 'gradient:#ffffff-#000000')
        img.scale(0.6)
        img.write('t.jpg')

    def test_scale_with_filtertype(self):
        img = Image((600, 400), 'gradient:#ffffff-#000000')
        img.scale(0.6, 'Catrom')
        img.write('t.jpg')
        m = hashlib.md5()
        with open('t.jpg', 'rb') as fp:
            m.update(fp.read())
            scale_with_filtertype_catrom_digest = m.hexdigest()
        img = Image((600, 400), 'gradient:#ffffff-#000000')
        img.scale(0.6, 'Cubic')
        img.write('t.jpg')
        m = hashlib.md5()
        with open('t.jpg', 'rb') as fp:
            m.update(fp.read())
            scale_with_filtertype_cubic_digest = m.hexdigest()
        img = Image((600, 400), 'gradient:#ffffff-#000000')
        img.scale(0.6)
        img.write('t.jpg')
        m = hashlib.md5()
        with open('t.jpg', 'rb') as fp:
            m.update(fp.read())
            scale_digest = m.hexdigest()
        self.assertNotEqual(scale_with_filtertype_catrom_digest, scale_digest)
        self.assertNotEqual(scale_with_filtertype_catrom_digest, scale_with_filtertype_cubic_digest)

    def test_composite_arg_list(self):
        base = Image((300, 200), 'green')
        layer = Image((300, 200), 'transparent')
        drawer = Draw()
        drawer.circle(50, 50, 50, 100)
        layer.draw(drawer)
        base.composite(layer, (10, 10), 'over')
        base.write('t.png')

    def test_composite_arg_gravity(self):
        base = Image((300, 200), 'green')
        layer = Image((150, 100), 'transparent')
        drawer = Draw()
        drawer.circle(50, 50, 20, 20)
        layer.draw(drawer)
        base.composite(layer, 'center', 'over')
        base.write('t.png')

    def test_crop(self):
        img = Image((300, 200), 'gradient:#ffff00-#00ffff')
        img.crop(20, 20, 50, 100)
        img.write('t.png')

    def test_fontpointsize(self):
        img = Image((300, 200), 'red')
        img.font_pointsize(60)
        self.assertEqual(60, img.font_pointsize())
        self.assertEqual(float, type(img.font_pointsize()))
        if sys.platform.lower() == 'darwin':
            img.font("/Library/Fonts/Arial.ttf")
        img.annotate("hello", (100, 100))
        img.write('t.png')

    def test_size_property(self):
        img = Image((500, 300), 'red')
        self.assertEqual(img.width, 500)
        self.assertEqual(img.height, 300)
        img.scale(0.5)
        self.assertEqual(img.width, 250)
        self.assertEqual(img.height, 150)


class DrawTestCase(unittest.TestCase):

    def setUp(self):
        self.img = Image((600, 400), 'red')
        self.d = Draw()

    def test_affine(self):
        self.d.affine(10, 10, 20, 20, 40, 40)
        self.img.draw(self.d.drawer)
        self.img.write('t.jpg')

    def test_arc(self):
        self.d.arc(30, 30, 40, 40, 40, 40)
        self.img.draw(self.d.drawer)
        self.img.write('t.jpg')

    def test_bezier(self):
        points = ((30, 30), (50, 75), (200, 100))
        self.d.bezier(points)
        self.img.draw(self.d.drawer)
        self.img.write('t.png')

    def test_circle(self):
        self.d.circle(40, 40, 50, 100)
        self.img.draw(self.d.drawer)
        self.img.write('t.png')

    def test_color(self):
        self.d.color(40, 40, 'point')
        self.img.draw(self.d.drawer)
        self.img.write('t.png')

    def test_composite(self):
        img1 = Image((20, 20), 'plasma:blue')
        self.d.composite(10, 10, 0, 0, img1)
        self.img.draw(self.d)
        self.img.write('t.png')

    def test_draw_for_draw_class(self):
        self.d.color(40, 40, 'point')
        self.d.circle(100, 100, 50, 100)
        self.img.draw(self.d)
        self.img.write('t.png')

    def test_ellipse(self):
        self.d.ellipse(150, 150, 120, 120, 0, 120)
        self.img.draw(self.d)
        self.img.write('t.png')

    def test_fill_color(self):
        self.d.fill_color('#f09060')
        self.d.ellipse(150, 150, 120, 120, 0, 120)
        self.img.draw(self.d)
        self.img.write('t.png')

    def test_fill_rule(self):
        self.d.fill_rule('evenodd')
        self.d.circle(150, 150, 50, 180)
        self.d.fill_rule('nonzero')
        self.d.circle(350, 150, 250, 180)
        self.img.draw(self.d.drawer)
        self.img.write('t.png')

    def test_fill_opacity(self):
        self.im = Image((600, 400), 'transparent')
        self.d.fill_color('red')
        self.d.fill_opacity(0.5)
        self.d.circle(150, 150, 50, 180)
        self.d.fill_color('green')
        self.d.fill_opacity(0.8)
        self.d.circle(160, 160, 50, 180)
        self.img.draw(self.d.drawer)
        self.img.write('t.png')

    def test_font_style_italic(self):
        if sys.platform.lower() == 'darwin':
            self.skipTest("DrawableFont() is broken")
        self.d.font('vera.ttf', 'italic')
        self.d.text(30, 30, "hello pgmagick")
        self.img.draw(self.d)
        self.img.write('t.png')

    def test_font_style_oblique(self):
        if sys.platform.lower() == 'darwin':
            self.skipTest("DrawableFont() is broken")
        self.d.font('vera.ttf', 'oblique')
        self.d.text(30, 30, "hello pgmagick")
        self.img.draw(self.d)
        self.img.write('t.png')

    def test_font_stretch_ultracondensed(self):
        if sys.platform.lower() == 'darwin':
            self.skipTest("DrawableFont() is broken")
        self.d.font('vera.ttf', 'oblique', stretch='ultracondensed')
        self.d.text(30, 30, "hello pgmagick")
        self.img.draw(self.d)
        self.img.write('t.png')

    def test_font_stretch_extraexpanded(self):
        if sys.platform.lower() == 'darwin':
            self.skipTest("DrawableFont() is broken")
        self.d.font('vera.ttf', 'oblique', stretch='extraexpanded')
        self.d.text(30, 30, "hello pgmagick")
        self.img.draw(self.d)
        self.img.write('t.png')

    def test_font_weight100(self):
        if sys.platform.lower() == 'darwin':
            self.skipTest("DrawableFont() is broken")
        self.d.font('vera.ttf', weight=100)
        self.d.text(30, 30, "hello pgmagick")
        self.img.draw(self.d)
        self.img.write('t.png')

    def test_font_bold(self):
        if sys.platform.lower() == 'darwin':
            self.skipTest("DrawableFont() is broken")
        self.d.font('vera.ttf', weight='bold')
        self.d.text(30, 30, "hello pgmagick")
        self.img.draw(self.d)
        self.img.write('t.png')

    def test_gravity(self):
        if sys.platform.lower() == 'darwin':
            self.skipTest("DrawableFont() is broken")
        self.d.gravity('center')
        self.d.text(0, 0, "hello pgmagick")
        self.img.draw(self.d)
        self.img.write('t.png')

    def test_line(self):
        self.d.line(10, 10, 40, 200)
        self.img.draw(self.d)
        self.img.write('t.png')

    def test_matte(self):
        self.d.matte(30, 30, 'filltoborder')
        self.img.draw(self.d)
        self.img.write('t.png')

    def test_miterlimit(self):
        self.d.miterlimit(1)
        self.d.stroke_color('black')
        self.d.stroke_width(3)
        self.d.line(10, 200, 100, 10)
        self.d.line(100, 10, 210, 200)
        self.img.draw(self.d)
        self.d = Draw()
        self.d.miterlimit(18)
        self.d.stroke_color('black')
        self.d.stroke_width(3)
        self.d.stroke_opacity(0.5)
        self.d.fill_opacity(0.5)
        self.d.line(210, 200, 300, 10)
        self.d.line(300, 10, 410, 200)
        self.img.draw(self.d)
        self.img.write('t.png')

    def test_path(self):
        paths = ((40, 30),)
        self.d.path(paths)
        self.img.draw(self.d.drawer)
        self.img.write('t.png')

    def test_point(self):
        for i in range(50):
            self.d.point(i, i + 10)
        for i in range(50, 200, 2):
            self.d.point(i, i + 10)
        self.img.draw(self.d.drawer)
        self.img.write('t.png')

    def test_pointsize(self):
        self.d.pointsize(10)
        self.d.pointsize(30.)
        self.d.circle(150, 150, 50, 180)
        self.img.draw(self.d.drawer)
        self.img.write('t.png')

    def test_polygon(self):
        coordinate = ((10, 10), (20, 30), (40, 50))
        self.d.polygon(coordinate)
        coordinate = [(100, 100), (150, 100), [150, 150], (100, 150)]
        self.d.polygon(coordinate)
        self.img.draw(self.d)
        self.img.write('t.png')

    def test_polyline(self):
        coordinate = ((10, 10), (20, 30), (40, 50))
        self.d.polyline(coordinate)
        coordinate = [(100, 100), (150, 100), [150, 150], (100, 150)]
        self.d.polyline(coordinate)
        self.img.draw(self.d)
        self.img.write('t.png')

    def test_rectangle(self):
        self.d.rectangle(50, 50, 100, 100)
        self.img.draw(self.d)
        self.img.write('t.png')

    def test_rotation(self):
        self.d.rectangle(150, 150, 200, 200)
        self.d.rotation(40)
        self.img.draw(self.d)
        self.d = Draw()
        self.d.fill_opacity(0.8)
        self.d.rectangle(150, 150, 200, 200)
        self.d.rotation(20)
        self.img.draw(self.d)
        self.d = Draw()
        self.d.fill_opacity(0.6)
        self.d.rectangle(150, 150, 200, 200)
        self.img.draw(self.d)
        self.img.write('t.png')

    def test_round_rectangle(self):
        self.d = Draw()
        self.d.round_rectangle(20, 20, 30, 30, 150, 150)
        self.img.draw(self.d)
        self.img.write('t.png')

    def test_scaling(self):
        self.d.scaling(0.4, 0.4)
        self.d.circle(150, 150, 150, 200)
        self.img.draw(self.d)
        self.d = Draw()
        self.d.fill_opacity(0.6)
        self.d.circle(150, 150, 150, 200)
        self.img.draw(self.d)
        self.img.write('t.png')

    def test_skew(self):
        self.d = Draw()
        self.d.fill_opacity(0.6)
        self.d.circle(50, 50, 50, 100)
        self.img.draw(self.d)
        self.d = Draw()
        self.d.fill_opacity(0.6)
        self.d.circle(50, 50, 50, 100)
        self.d.skewx(40)
        self.img.draw(self.d)
        self.d = Draw()
        self.d.fill_opacity(0.6)
        self.d.circle(50, 50, 50, 100)
        self.d.skewy(40)
        self.img.draw(self.d)
        self.img.write('t.png')

    def test_stroke_antialias(self):
        self.d.stroke_color('black')
        self.d.stroke_width(20)
        self.d.stroke_antialias(True)
        self.d.line(10, 10, 40, 200)
        self.d.stroke_antialias(False)
        self.d.line(50, 10, 80, 200)
        self.img.draw(self.d)
        self.img.write('t.png')

    def test_stroke_linecap(self):
        self.d.stroke_color('lime')
        self.d.stroke_linecap('butt')
        self.d.stroke_linecap('round')
        self.d.stroke_linecap('square')
        self.d.line(10, 10, 40, 200)
        self.img.draw(self.d)
        self.img.write('t.png')

    @unittest.skipIf(LIBGM_VERSION <= [1, 3, 18], "bug in gm version: %s" % str(LIBGM_VERSION))
    def test_stroke_linejoin(self):
        self.d.stroke_color('lime')
        self.d.stroke_linejoin('round')
        self.d.stroke_linejoin('bevel')
        self.d.stroke_linejoin('miter')
        self.d.line(10, 10, 40, 200)
        self.img.draw(self.d)
        self.img.write('t.png')

    def test_stroke_color(self):
        self.d.stroke_color('lime')
        self.d.line(10, 10, 40, 200)
        self.img.draw(self.d)
        self.img.write('t.png')

    def test_stroke_width(self):
        self.d.stroke_width(20)
        self.d.line(20, 20, 50, 210)
        self.img.draw(self.d)
        self.img.write('t.png')

    def test_text(self):
        if sys.platform.lower() == 'darwin':
            self.skipTest("DrawableFont() is broken")
        self.d.text(30, 30, "hello pgmagick")
        self.img.draw(self.d)
        self.img.write('t.png')

    def test_text_antialias(self):
        if sys.platform.lower() == 'darwin':
            self.skipTest("DrawableFont() is broken")
        self.d.font('courier', weight='bold')
        self.d.pointsize(70)
        self.d.text_antialias(False)
        self.d.text(30, 100, "hello pgmagick")
        self.d.text_antialias(True)
        self.d.text(30, 200, "hello pgmagick")
        self.img.draw(self.d)
        self.img.write('t.png')

    def test_text_decoration(self):
        if sys.platform.lower() == 'darwin':
            self.skipTest("DrawableFont() is broken")
        self.d.pointsize(70)
        self.d.text_decoration('overline')
        self.d.text(30, 100, "hello pgmagick")
        self.d.text_decoration('linethrough')
        self.d.text(30, 200, "hello pgmagick")
        self.d.text_decoration('underline')
        self.d.text(30, 300, "hello pgmagick")
        self.img.draw(self.d)
        self.img.write('t.png')

    def test_text_undercolor(self):
        if sys.platform.lower() == 'darwin':
            self.skipTest("DrawableFont() is broken")
        self.d.pointsize(70)
        self.d.text_undercolor('lime')
        self.d.text(30, 100, "hello pgmagick")
        self.img.draw(self.d)
        self.img.write('t.png')

    def test_translate(self):
        self.d.translate(10, 200)
        self.img.draw(self.d)
        self.img.write('t.png')


unittest.main()
