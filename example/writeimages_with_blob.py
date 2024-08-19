import pgmagick

im = pgmagick.Image('X.jpg')

pdf = pgmagick.ImageList()
pdf.append(im)
pdf.append(im)
pdf.writeImages('new.pdf')

blob = pgmagick.Blob()
pdf.writeImages(blob)
print(blob.length())
