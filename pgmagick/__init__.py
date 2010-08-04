import _pgmagick


class Image(_pgmagick.Image):
    pass


class FilterTypes(_pgmagick.FilterTypes):
    pass

#class Blob(_pgmmagick.Blob):
#    def __init__(self, *args):
#        if len(args) == 1 and type(args[0]) == type(''):
#            _pgmagick.Blob.__init__(self)
#            self.update(args[0])
#        else:
#            _pgmagick.Blob.__init__(self, *args)
#    data = property(_pgmagick.get_blob_data, _pgmagick.Blob.update)
