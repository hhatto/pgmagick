from pgmagick import Image, StorageType

data = ["000" for i in range(100)]
img = Image(100, 100, "RGB", StorageType.CharPixel, "".join(data))
img.display()
