from pgmagick import Blob, Image, Color, Geometry

blob = Blob(open('example.png', 'rb').read())
img = Image(blob)
img.write('from_blob_to_image.png')
