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

    #def test_image_getpixels(self):
    #    img = Image(Geometry(300, 200), Color('transparent'))
    #    img.getPixels(10, 10, 10, 10)

    def test_image_init_storagetype(self):
        data = ["0" for i in range(10000)]
        img = Image(100, 100, "RGB", StorageType.CharPixel, "".join(data))
        del(img)

    #def test_haldClut(self):
    #    img = Image()
    #    if hasattr(img, "haldClut"):
    #        clutimg = Image(Geometry(400, 300), Color("transparent"))
    #        clutimg.read("gradient:white-black")
    #        img.haldClut(clutimg)

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
