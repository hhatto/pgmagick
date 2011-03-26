from benchmarker import Benchmarker
import Image
import pgmagick
import opencv.cv as cv
import opencv.highgui as highgui
import kaa.imlib2 as imlib2
try:
    import pyimlib2
except ImportError:
    "pyimlib2 not work"
import gd

N = 1


def gd_scale(filename, width, height):
    im = gd.image(filename)
    newim = gd.image((width, height))
    size = im.size()
    im.copyPaletteTo(newim)
    im.copyResampledTo(newim,
                     (0, 0), (0, 0),
                     (width, height), (size[0], size[1]))
    newim.writeJpeg('outgd.jpg', 95)


def imlib2_scale(filename, width, height):
    im = imlib2.Image(filename)
    newim = im.scale((width, height))
    newim.save('outimlib2.jpg')


def pyimlib2_scale(filename, width, height):
    im = pyimlib2.open(filename)
    newim = im.scaled_image(width, height)
    newim.save('outpyimlib2.jpg', 'jpeg', 95)


def pyimlib2_scale_with_pgmagicksharpen(filename, width, height):
    im = pyimlib2.open(filename)
    newim = im.scaled_image(width, height)
    newim.save('outpyimlib2.jpg', 'jpeg', 95)
    im = pgmagick.Image('outpyimlib2.jpg')
    im.sharpen(1)
    im.write('outpyimlib2_with_sharpen.jpg')


def pil_scale(filename, width, height):
    im = Image.open(filename)
    newim = im.resize((width, height), Image.ANTIALIAS)
    newim.save('outpil.jpg', quality=95)


def imagemagick_scale_plus_sharpen(filename, width, height):
    im = PythonMagick.Image(filename)
    im.scale('%dx%d' % (width, height))
    im.sharpen(1)
    im.quality(95)
    im.write('outimsharpen.jpg')


def imagemagick_scale(filename, width, height):
    im = PythonMagick.Image(filename)
    im.quality(95)
    im.scale('%dx%d' % (width, height))
    im.write('outim.jpg')


def pgmagick_scale_plus_sharpen(filename, width, height):
    im = pgmagick.Image(pgmagick.Blob(open(filename).read()),
                        pgmagick.Geometry(width, height))
    im.scale('%dx%d' % (width, height))
    im.sharpen(1)
    im.quality(95)
    im.write('outpgsharpen.jpg')


def pgmagick_scale_from_blob(filename, width, height):
    im = pgmagick.Image(pgmagick.Blob(open(filename).read()),
                        pgmagick.Geometry(width, height))
    im.scale('%dx%d' % (width, height))
    im.quality(95)
    im.write('outpg_fromblob.jpg')


def pgmagick_scale(filename, width, height):
    im = pgmagick.Image(filename)
    im.scale('%dx%d' % (width, height))
    im.quality(95)
    im.write('outpg.jpg')


def opencv_scale(filename, width, height):
    im = highgui.cvLoadImage(filename)
    newim = cv.cvCreateImage(cv.cvSize(width, height), 8, 3)
    cv.cvResize(im, newim, cv.CV_INTER_AREA)
    highgui.cvSaveImage("outcv.jpg", newim)


def exebench(width):
    """
    benchorg.jpg is
    'http://upload.wikimedia.org/wikipedia/commons/d/df/SAND_LUE.jpg'
    """
    height = width * 2 / 3
    with Benchmarker(width=30, loop=N) as bm:
        for i in bm('kaa.imlib2'):
            imlib2_scale('benchorg.jpg', width, height)
        for i in bm("PIL"):
            pil_scale('benchorg.jpg', width, height)
        for i in bm("pgmagick(blob-read)"):
            pgmagick_scale_from_blob('benchorg.jpg', width, height)
        for i in bm("pgmagick(normal-read)"):
            pgmagick_scale('benchorg.jpg', width, height)
        for i in bm("pgmagick(scale+sharpen)"):
            pgmagick_scale_plus_sharpen('benchorg.jpg', width, height)
        for i in bm("opencv"):
            opencv_scale('benchorg.jpg', width, height)
        for i in bm("pyimlib2"):
            pyimlib2_scale('benchorg.jpg', width, height)
        for i in bm("pyimlib2_with_pgsharpen"):
            pyimlib2_scale_with_pgmagicksharpen('benchorg.jpg', width, height)
    return bm.results


def make_graph(results):
    g = SideBar()
    g.title = "Benchmark of Python Image Processing\n"\
              "resized, 10times, original image size 4288x2848\n" \
              "(on Ubuntu10.04, python2.6.5, Core2 Duo 1.40GHz)"
    g.title_font_size = 18.5
    g.legend_font_size = 18.5
    g.title_margin = 55
    g.right_margin -= 50
    g.sort = False
    g.x_axis_label = '[sec]'
    g.y_axis_label = 'modules'
    g.legend_font_size = 16
    g.theme_greyscale()
    small = [i.real for i in results['small']]
    medium = [i.real for i in results['medium']]
    large = [i.real for i in results['large']]
    g.data("small(180x120)", small)
    g.data("medium(600x400)", medium)
    g.data("large(1200x800)", large)
    g.labels = {0: 'kaa.imlib2',
                1: 'PIL',
                2: 'pgmagick(blob-read)',
                3: 'pgmagick(normal-read)',
                4: 'pgmagick(scale+sharpen)',
                5: 'opencv',
                6: 'pyimlib2',
                7: 'pyimlib2(+pgsharpen)'}
    g.display()
    g.write("test_gruffy.png")


if __name__ == '__main__':
    r = {}
    r['small'] = exebench(180)
    print "=" * 70
    r['medium'] = exebench(600)
    print "=" * 70
    r['large'] = exebench(1200)
    try:
        from gruffy import SideBar
        make_graph(r)
    except ImportError:
        pass
