import sys
import unittest
from pgmagick import Image, Geometry, Color, LineJoin, gminfo


class TestImage(unittest.TestCase):

    def test_noarg_init(self):
        im = Image()
        self.assertEqual(type(im), Image)

    def test_fromfile_init_error(self):
        self.assertRaises(RuntimeError, Image, "xXxX.jpg")

    def test_size_and_color_init(self):
        im = Image(Geometry(300, 200), Color('transparent'))
        size = im.size()
        self.assertEqual(300, size.width())
        self.assertEqual(200, size.height())

    def test_stroke_linejoin(self):
        im = Image(Geometry(300, 200), Color('transparent'))
        im.strokeLineJoin(LineJoin.MiterJoin)
        im.strokeLineJoin(LineJoin.RoundJoin)
        im.strokeLineJoin(LineJoin.BevelJoin)


class TestIMImage(unittest.TestCase):

    def setUp(self):
        self.img = Image()
        self.is_imagemagick = False
        if gminfo.library == 'ImageMagick':
            self.is_imagemagick = True

    def test_adaptiveBlur(self):
        if self.is_imagemagick:
            self.img.adaptiveBlur()

unittest.main()
