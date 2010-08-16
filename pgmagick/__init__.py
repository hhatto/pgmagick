import _pgmagick

FilterTypes = _pgmagick.FilterTypes


class Blob(_pgmagick.Blob):
    pass


class Geometry(_pgmagick.Geometry):
    pass


class Image(_pgmagick.Image):
    pass


class Color(_pgmagick.Color):
    pass


class ColorHSL(_pgmagick.ColorHSL):
    pass


class ColorGray(_pgmagick.ColorGray):
    pass


class ColorMono(_pgmagick.ColorMono):
    pass


class ColorRGB(_pgmagick.ColorRGB):
    pass


class ColorYUV(_pgmagick.ColorYUV):
    pass


class Montage(_pgmagick.Montage):
    pass
