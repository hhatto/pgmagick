import unittest
import pgmagick
from pgmagick import Blob, Image, Geometry, Color, LineJoin, StorageType, FilterTypes
from pgmagick import ChannelType
from pgmagick import gminfo
if gminfo.library == 'ImageMagick':
    from pgmagick import DistortImageMethod, SparseColorMethod

libgm_version = [int(v) for v in pgmagick.gminfo().version.split('.')]


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

    def getpixels_test_template(self, use_const):
        img = Image(Geometry(300, 200), Color('transparent'))
        getPixelsMethod = img.getConstPixels if use_const else img.getPixels
        pixels = getPixelsMethod(40, 50, 10, 10)
        self.assertEqual(10 * 10, len(pixels))
        with self.assertRaises(IndexError):
            pixels[2000]
        colorMax = Color.scaleDoubleToQuantum(1.0)
        self.assertEqual(0, pixels[0].red)
        self.assertEqual(0, pixels[0].blue)
        self.assertEqual(0, pixels[0].green)
        self.assertEqual(colorMax, pixels[0].opacity)
        return pixels

    def test_image_getpixels(self):
        self.getpixels_test_template(use_const=False)

    def test_image_getconstpixels(self):
        pixels = self.getpixels_test_template(use_const=True)
        # either throw AttributeError (write to readonly field)
        # or at least don't update original data (elements returned by indexing are cloned)
        try:
            pixels[0].red = 50
            self.assertEqual(pixels[0].red, 0)
        except AttributeError:
            pass

    def test_image_setpixels(self):
        img = Image(Geometry(300, 200), Color('transparent'))
        pixels = img.setPixels(40, 50, 5, 5)
        for pixel in pixels:
            pixel.red = 50
        img.syncPixels()

        for pixel in img.getPixels(40, 50, 5, 5):
            self.assertEqual(50, pixel.red)

    def test_image_init_storagetype(self):
        data = ["0" for i in range(10000)]
        img = Image(100, 100, "RGB", StorageType.CharPixel, "".join(data))
        del(img)

    @unittest.skip("do not know how to use haldClut method")
    def test_haldClut(self):
        img = Image()
        if hasattr(img, "haldClut"):
            clutimg = Image(Geometry(512, 512), Color('transparent'))
            img.haldClut(clutimg)

    @unittest.skipIf(libgm_version < [1, 3, 21], "not support gm version: %s" % str(libgm_version))
    def test_extent(self):
        im = Image(Geometry(300, 200), Color('transparent'))
        g = Geometry(10, 10)
        im.extent(g)

    @unittest.skipIf(libgm_version < [1, 3, 19], "not support gm version: %s" % str(libgm_version))
    def test_image_thumbnail(self):
        im = Image(Geometry(300, 200), Color('transparent'))
        g = Geometry(150, 100)
        im.thumbnail(g)

    @unittest.skipIf(libgm_version < [1, 3, 22], "not support gm version: %s" % str(libgm_version))
    def test_image_resize(self):
        im = Image(Geometry(300, 200), Color('transparent'))
        g = Geometry(150, 100)
        ft = FilterTypes.BlackmanFilter
        blur = 0.5
        im.resize(g, ft, blur)
        im.resize(g, ft)
        im.resize(g)

    def test_color_histogram(self):
        redColor = Color('red')
        im = Image(Geometry(30, 20), redColor)
        histogram = im.colorHistogram()
        self.assertEqual(1, len(histogram))
        # test in, __getitem__
        self.assertIn(redColor, histogram)
        self.assertEqual(30 * 20, histogram[redColor])
        # iteration example
        for packet in histogram:
            color, count = packet.key(), packet.data()
            self.assertEqual(redColor, color)
            self.assertEqual(30 * 20, count)


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

    def test_inverseFourierTransform(self):
        if self.is_imagemagick:
            phase = Image()
            self.img.inverseFourierTransform(phase)

    def test_sigmoidalContrast(self):
        if self.is_imagemagick:
            self.img.sigmoidalContrast(2, 2.)

    def test_splice(self):
        if self.is_imagemagick:
            self.img.splice(Geometry(100, 100))

    def test_sparseColor(self):
        if self.is_imagemagick:
            self.img.sparseColor(ChannelType.RedChannel,
                                 SparseColorMethod.PolynomialColorInterpolate,
                                 1, 1.)

    def test_exif_profile(self):
        if self.is_imagemagick:
            ret = self.img.exifProfile()
            self.assertEqual(type(ret), type(pgmagick._pgmagick.Blob()))

    def test_virtualPixelMethod(self):
        if self.is_imagemagick:
            ret = self.img.virtualPixelMethod()
            self.assertEqual(type(ret),
                             type(pgmagick._pgmagick.VirtualPixelMethod()))


class TestImageWithBlob(unittest.TestCase):

    def test_fromblob(self):
        with open('../example/X.jpg', 'rb') as f:
            data = f.read()
            self.assertEqual(True, type(data) in (bytes, str))
            b = Blob(data)
            img = Image(b)
            img.write('X2.jpg')
            self.assertEqual(type(img), Image)


unittest.main()
