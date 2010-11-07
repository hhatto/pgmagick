import unittest
import sys
sys.path.append('../')
sys.path.append('./')
from pgmagick.api import Image, Draw


class ImageTestCase(unittest.TestCase):

    def test_nonarg(self):
        im = Image()

    def test_arg(self):
        im = Image((600, 400), 'red')

    def test_arg_float(self):
        im = Image((600.5, 400.4), 'red')

    def test_size(self):
        im = Image((600, 400), 'red')
        self.assertEqual(im.height, 400)
        self.assertEqual(im.width, 600)

    def test_scale(self):
        im = Image((600, 400), 'red')
        im.scale(0.6)
        im.write('t.jpg')


class DrawTestCase(unittest.TestCase):

    def setUp(self):
        self.im = Image((600, 400), 'red')
        self.d = Draw()

    def test_affine(self):
        self.d.affine(10, 10, 20, 20, 40, 40)
        self.im.draw(self.d.drawer)
        self.im.write('t.jpg')

    def test_arc(self):
        self.d.arc(30, 30, 40, 40, 40, 40)
        self.im.draw(self.d.drawer)
        self.im.write('t.jpg')

    def test_bezier(self):
        points = ((30, 30), (50, 75), (200, 100))
        self.d.bezier(points)
        self.im.draw(self.d.drawer)
        self.im.write('t.png')

    def test_circle(self):
        self.d.circle(40, 40, 50, 100)
        self.im.draw(self.d.drawer)
        self.im.write('t.png')

    def test_color(self):
        self.d.color(40, 40, 'point')
        self.im.draw(self.d.drawer)
        self.im.write('t.png')

    def test_draw_for_draw_class(self):
        self.d.color(40, 40, 'point')
        self.d.circle(100, 100, 50, 100)
        self.im.draw(self.d)
        self.im.write('t.png')

unittest.main()
