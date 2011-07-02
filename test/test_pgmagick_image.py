import sys
import unittest
from pgmagick import Image, Geometry, Color, LineJoin, DistortImageMethod
from pgmagick import gminfo


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

    def test_haldClut(self):
        img = Image()
        if hasattr(img, "haldClut"):
            clutimg = Image()
            img.haldClut(clutimg)


class TestIMImage(unittest.TestCase):

    def setUp(self):
        self.img = Image()
        self.is_imagemagick = False
        if gminfo.library == 'ImageMagick':
            self.is_imagemagick = True

    def test_adaptiveBlur(self):
        if self.is_imagemagick:
            self.img.adaptiveBlur()

    def test_distort(self):
        if self.is_imagemagick:
            self.img.distort(DistortImageMethod.ScaleRotateTranslateDistortion,
                             1, 1.0, True)

    def test_extent(self):
        if self.is_imagemagick:
            self.img.extent(Geometry(100, 100))

    def test_inverseFourierTransform(self):
        if self.is_imagemagick:
            phase = Image()
            self.img.inverseFourierTransform(phase)

unittest.main()
