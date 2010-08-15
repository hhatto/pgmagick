import _pgmagick


class Blob(_pgmagick.Blob):
    pass


class Geometry(_pgmagick.Geometry):
    pass


class Image(_pgmagick.Image):
    pass


FilterTypes = _pgmagick.FilterTypes


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

#class Blob(_pgmmagick.Blob):
#    def __init__(self, *args):
#        if len(args) == 1 and type(args[0]) == type(''):
#            _pgmagick.Blob.__init__(self)
#            self.update(args[0])
#        else:
#            _pgmagick.Blob.__init__(self, *args)
#    data = property(_pgmagick.get_blob_data, _pgmagick.Blob.update)
