# coding: utf-8
import os.path
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
        img.annotate('Hello World')
        img.write(self.tmp_filename_png)

    def test_annotate_with_angle45(self):
        img = api.Image((300, 200))
        img.annotate('Hello World', angle=45)
        img.write(self.tmp_filename_png)

    def test_annotate_with_japanese_font(self):
        img = api.Image((300, 200))
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

    def test_scale_jpeg(self):
        img = api.Image((400, 400), 'blue')
        img.write(self.tmp_filename_jpg)
        img2 = Image(Blob(open(self.tmp_filename_jpg).read()),
                     Geometry(200, 200))
        img2.scale('200x200')
        img2.write(self.tmp_filename_jpg)

if __name__ == '__main__':
    unittest.main()
