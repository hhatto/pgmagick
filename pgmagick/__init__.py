from pgmagick import _pgmagick
__version__ = '0.4.2'


def __init():
    _pgmagick.InitializeMagick("./")
__init()


class Blob(_pgmagick.Blob):

    def __init__(self, *args):
        if len(args) == 1 and isinstance(args[0], str):
            _pgmagick.Blob.__init__(self)
            self.update(args[0])
        else:
            _pgmagick.Blob.__init__(self, *args)

    data = property(_pgmagick.get_blob_data, _pgmagick.Blob.update)

ChannelType = _pgmagick.ChannelType

class Color(_pgmagick.Color):
    pass

class ColorGray(_pgmagick.ColorGray):
    pass

class ColorHSL(_pgmagick.ColorHSL):
    pass

class ColorMono(_pgmagick.ColorMono):
    pass

class ColorRGB(_pgmagick.ColorRGB):
    pass

class ColorYUV(_pgmagick.ColorYUV):
    pass

ColorspaceType = _pgmagick.ColorspaceType

CompositeOperator = _pgmagick.CompositeOperator

CompressionType = _pgmagick.CompressionType

class Coordinate(_pgmagick.Coordinate):
    pass

class CoordinateList(_pgmagick.CoordinateList):
    pass

DecorationType = _pgmagick.DecorationType

class Drawable(_pgmagick.Drawable):
    pass

class DrawableAffine(_pgmagick.DrawableAffine):
    pass

class DrawableArc(_pgmagick.DrawableArc):
    pass

class DrawableBezier(_pgmagick.DrawableBezier):
    pass

class DrawableCircle(_pgmagick.DrawableCircle):
    pass

class DrawableClipPath(_pgmagick.DrawableClipPath):
    pass

class DrawableColor(_pgmagick.DrawableColor):
    pass

class DrawableCompositeImage(_pgmagick.DrawableCompositeImage):
    pass

class DrawableDashArray(_pgmagick.DrawableDashArray):
    pass

class DrawableDashOffset(_pgmagick.DrawableDashOffset):
    pass

class DrawableEllipse(_pgmagick.DrawableEllipse):
    pass

class DrawableFillColor(_pgmagick.DrawableFillColor):
    pass

class DrawableFillOpacity(_pgmagick.DrawableFillOpacity):
    pass

class DrawableFillRule(_pgmagick.DrawableFillRule):
    pass

class DrawableFont(_pgmagick.DrawableFont):
    pass

class DrawableGravity(_pgmagick.DrawableGravity):
    pass

class DrawableLine(_pgmagick.DrawableLine):
    pass

class DrawableList(_pgmagick.DrawableList):
    pass

class DrawableMatte(_pgmagick.DrawableMatte):
    pass

class DrawableMiterLimit(_pgmagick.DrawableMiterLimit):
    pass

class DrawablePath(_pgmagick.DrawablePath):
    pass

class DrawablePoint(_pgmagick.DrawablePoint):
    pass

class DrawablePointSize(_pgmagick.DrawablePointSize):
    pass

class DrawablePolygon(_pgmagick.DrawablePolygon):
    pass

class DrawablePolyline(_pgmagick.DrawablePolyline):
    pass

class DrawablePopClipPath(_pgmagick.DrawablePopClipPath):
    pass

class DrawablePopGraphicContext(_pgmagick.DrawablePopGraphicContext):
    pass

class DrawablePopPattern(_pgmagick.DrawablePopPattern):
    pass

class DrawablePushClipPath(_pgmagick.DrawablePushClipPath):
    pass

class DrawablePushGraphicContext(_pgmagick.DrawablePushGraphicContext):
    pass

class DrawablePushPattern(_pgmagick.DrawablePushPattern):
    pass

class DrawableRectangle(_pgmagick.DrawableRectangle):
    pass

class DrawableRotation(_pgmagick.DrawableRotation):
    pass

class DrawableRoundRectangle(_pgmagick.DrawableRoundRectangle):
    pass

class DrawableScaling(_pgmagick.DrawableScaling):
    pass

class DrawableSkewX(_pgmagick.DrawableSkewX):
    pass

class DrawableSkewY(_pgmagick.DrawableSkewY):
    pass

class DrawableStrokeAntialias(_pgmagick.DrawableStrokeAntialias):
    pass

class DrawableStrokeColor(_pgmagick.DrawableStrokeColor):
    pass

class DrawableStrokeLineCap(_pgmagick.DrawableStrokeLineCap):
    pass

class DrawableStrokeLineJoin(_pgmagick.DrawableStrokeLineJoin):
    pass

class DrawableStrokeOpacity(_pgmagick.DrawableStrokeOpacity):
    pass

class DrawableStrokeWidth(_pgmagick.DrawableStrokeWidth):
    pass

class DrawableText(_pgmagick.DrawableText):
    pass

class DrawableTextAntialias(_pgmagick.DrawableTextAntialias):
    pass

class DrawableTextDecoration(_pgmagick.DrawableTextDecoration):
    pass

class DrawableTextUnderColor(_pgmagick.DrawableTextUnderColor):
    pass

class DrawableTranslation(_pgmagick.DrawableTranslation):
    pass

class DrawableViewbox(_pgmagick.DrawableViewbox):
    pass

EndianType = _pgmagick.EndianType

class Exception(_pgmagick.Exception):
    pass

FillRule = _pgmagick.FillRule

FilterTypes = _pgmagick.FilterTypes

class Geometry(_pgmagick.Geometry):
    pass

GravityType = _pgmagick.GravityType

class Image(_pgmagick.Image):
    pass

class ImageList(_pgmagick.ImageList):
    pass

ImageType = _pgmagick.ImageType

InterlaceType = _pgmagick.InterlaceType

LineCap = _pgmagick.LineCap

LineJoin = _pgmagick.LineJoin

class Montage(_pgmagick.Montage):
    pass

class MontageFramed(_pgmagick.MontageFramed):
    pass

NoiseType = _pgmagick.NoiseType

if hasattr(_pgmagick, "OrientationType"):
    OrientationType = _pgmagick.OrientationType

PaintMethod = _pgmagick.PaintMethod

class PathArcAbs(_pgmagick.PathArcAbs):
    pass

class PathArcArgs(_pgmagick.PathArcArgs):
    pass

class PathArcArgsList(_pgmagick.PathArcArgsList):
    pass

class PathArcRel(_pgmagick.PathArcRel):
    pass

class PathClosePath(_pgmagick.PathClosePath):
    pass

class PathCurveToArgsList(_pgmagick.PathCurveToArgsList):
    pass

class PathCurvetoAbs(_pgmagick.PathCurvetoAbs):
    pass

class PathCurvetoArgs(_pgmagick.PathCurvetoArgs):
    pass

class PathCurvetoRel(_pgmagick.PathCurvetoRel):
    pass

class PathLinetoAbs(_pgmagick.PathLinetoAbs):
    pass

class PathLinetoHorizontalAbs(_pgmagick.PathLinetoHorizontalAbs):
    pass

class PathLinetoHorizontalRel(_pgmagick.PathLinetoHorizontalRel):
    pass

class PathLinetoRel(_pgmagick.PathLinetoRel):
    pass

class PathLinetoVerticalAbs(_pgmagick.PathLinetoVerticalAbs):
    pass

class PathLinetoVerticalRel(_pgmagick.PathLinetoVerticalRel):
    pass

class PathMovetoAbs(_pgmagick.PathMovetoAbs):
    pass

class PathMovetoRel(_pgmagick.PathMovetoRel):
    pass

class PathQuadraticCurvetoAbs(_pgmagick.PathQuadraticCurvetoAbs):
    pass

class PathQuadraticCurvetoArgs(_pgmagick.PathQuadraticCurvetoArgs):
    pass

class PathQuadraticCurvetoArgsList(_pgmagick.PathQuadraticCurvetoArgsList):
    pass

class PathQuadraticCurvetoRel(_pgmagick.PathQuadraticCurvetoRel):
    pass

class PathSmoothCurvetoAbs(_pgmagick.PathSmoothCurvetoAbs):
    pass

class PathSmoothCurvetoRel(_pgmagick.PathSmoothCurvetoRel):
    pass

class PathSmoothQuadraticCurvetoAbs(_pgmagick.PathSmoothQuadraticCurvetoAbs):
    pass

class PathSmoothQuadraticCurvetoRel(_pgmagick.PathSmoothQuadraticCurvetoRel):
    pass

class Pixels(_pgmagick.Pixels):
    pass

if hasattr(_pgmagick, "SparseColorMethod"):
    SparseColorMethod = _pgmagick.SparseColorMethod

if hasattr(_pgmagick, "DistortImageMethod"):
    DistortImageMethod = _pgmagick.DistortImageMethod

if hasattr(_pgmagick, "QuantumOperator"):
    QuantumOperator = _pgmagick.QuantumOperator

QuantumType = _pgmagick.QuantumType

RenderingIntent = _pgmagick.RenderingIntent

ResolutionType = _pgmagick.ResolutionType

StorageType = _pgmagick.StorageType

StretchType = _pgmagick.StretchType

StyleType = _pgmagick.StyleType

class TypeMetric(_pgmagick.TypeMetric):
    pass

if hasattr(_pgmagick, "VirtualPixelMethod"):
    VirtualPixelMethod = _pgmagick.VirtualPixelMethod

class VPath(_pgmagick.VPath):
    pass

class VPathList(_pgmagick.VPathList):
    pass

class gminfo:
    version = _pgmagick.get_version()
    library = _pgmagick.get_library()
