from pgmagick import Image, Blob

blob = Blob(open('X.jpg', 'rb').read())
img = Image(blob)
size = img.size()
pixels = img.getPixels(0, 0, int(size.width()/2), int(size.height()/2))

for cnt, pixel in enumerate(pixels):
    if False:
        print(pixel.red, pixel.blue, pixel.green, pixel.opacity)
    pixel.blue = int(pixel.blue / 2)
    pixel.green = int(pixel.green / 2)
    pixel.red = int(pixel.red / 2)
img.syncPixels()
img.write("Xo.jpg")
