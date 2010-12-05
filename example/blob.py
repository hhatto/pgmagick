from pgmagick import Blob, Image, Color, Geometry

blob = Blob(open('example.png').read())
#print dir(blob)
#print len(blob.data)
#print blob.length()
img = Image(blob)
img.write('from_blob_to_image.png')
