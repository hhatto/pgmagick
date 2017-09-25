from pgmagick import Image, Blob

blob = Blob(open('X.jpg').read())
img = Image(blob)
size = img.size()
pixels = img.getPixels(0, 0, size.width()/2, size.height()/2)

for cnt, pixel in enumerate(pixels):
    if False:
        print(pixel.red, pixel.blue, pixel.green, pixel.opacity)
    pixel.blue = pixel.blue / 2
    pixel.green = pixel.green / 2
    pixel.red = pixel.red / 2
img.syncPixels()
img.write("Xo.jpg")
