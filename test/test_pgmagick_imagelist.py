import unittest
from pgmagick import ImageList


class TestImageList(unittest.TestCase):

    def test_noarg(self):
        imgs = ImageList()
        self.assertEqual(type(imgs), ImageList)

unittest.main()
