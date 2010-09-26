from pgmagick import Image, Geometry, Color

im = Image(Geometry(400, 300), Color("transparent"))
im.read("gradient:white-black")
im.display()
im.read("gradient:#f0f000-#f000f0")
im.display()
