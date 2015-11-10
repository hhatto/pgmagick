# coding: utf-8
import os.path
import sys
import unittest
from pgmagick import api
from pgmagick import Image, Geometry, Blob


class TestCookbook(unittest.TestCase):

    def setUp(self):
        self.tmp_filename_jpg = "_cookbook_test.jpg"
        self.tmp_filename_png = "_cookbook_test.png"

    def tearDown(self):
        if os.path.exists(self.tmp_filename_jpg):
            os.remove(self.tmp_filename_jpg)
        if os.path.exists(self.tmp_filename_png):
            os.remove(self.tmp_filename_png)

    def test_red_background_jpeg_image(self):
        img = api.Image((300, 200), 'red')
        img.write(self.tmp_filename_jpg)

    def test_transparent_png_image(self):
        img = api.Image((300, 200), 'transparent')
        img.write(self.tmp_filename_png)

    def test_gradient_png_image(self):
        img = api.Image((300, 200), 'gradient:#ffffff-#000000')
        img.write(self.tmp_filename_png)

    def test_annotate(self):
        img = api.Image((300, 200))
        if sys.platform.lower() == 'darwin':
            img.font("/Library/Fonts/Arial.ttf")
        img.annotate('Hello World')
        img.write(self.tmp_filename_png)

    def test_annotate_with_angle45(self):
        img = api.Image((300, 200))
        if sys.platform.lower() == 'darwin':
            img.font("/Library/Fonts/Arial.ttf")
        img.annotate('Hello World', angle=45)
        img.write(self.tmp_filename_png)

    def test_annotate_with_japanese_font(self):
        img = api.Image((300, 200))
        if sys.platform.lower() == 'darwin':
            img.font("/System/Library/Fonts/Hiragino Sans GB W3.ttc")
        else:
            # TODO: not support windows
            img.font("/usr/share/fonts/truetype/ttf-japanese-gothic.ttf")
        img.annotate('ようこそpgmagickへ!!')
        img.write(self.tmp_filename_png)

    def test_scale(self):
        img = api.Image((300, 200), 'blue')
        img.write(self.tmp_filename_png)
        img2 = api.Image(self.tmp_filename_png)
        img2.scale(0.5)
        img2.write(self.tmp_filename_png)
        self.assertEqual(img2.width, 150)
        self.assertEqual(img2.height, 100)

    def test_scale_with_lanczos(self):
        img = api.Image((300, 200), 'blue')
        img.write(self.tmp_filename_png)
        img2 = api.Image(self.tmp_filename_png)
        img2.scale((150, 100), 'lanczos')
        img2.write(self.tmp_filename_png)
        self.assertEqual(img2.width, 150)
        self.assertEqual(img2.height, 100)

    @unittest.skipIf(sys.version_info[0] == 3, "not support python3.x")
    def test_scale_jpeg(self):
        img = api.Image((400, 400), 'blue')
        img.write(self.tmp_filename_jpg)
        with open(self.tmp_filename_jpg, 'rb') as fp:
            b = Blob(str(fp.read()))
            img2 = Image(b, Geometry(200, 200))
            if sys.platform.lower() == 'darwin':
                # NOTE: error occur when use '200x200' param
                #       -----------------------------------------------------
                #       RuntimeError: Magick: Application transferred too few
                #       scanlines (x.jpg) reported by coders/jpeg.c:344 (JPEGErrorHandler)
                img2.scale('199x199')
            else:
                img2.scale('200x200')
            img2.write(self.tmp_filename_jpg)

if __name__ == '__main__':
    unittest.main()
