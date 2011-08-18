FLAGS = -Wall
INCS = -I/usr/include/python2.6 -I/usr/include/GraphicsMagick
SO = _pgmagick.so
LIBS = -lboost_python -lGraphicsMagick++
OBJS = _Blob.o \
       _ChannelType.o \
       _Color.o \
       _ColorspaceType.o \
       _CompositeOperator.o \
       _CompressionType.o \
       _Coordinate.o \
       _DecorationType.o \
       _DistortImageMethod.o \
       _Drawable.o \
       _DrawableAffine.o \
       _DrawableArc.o \
       _DrawableBezier.o \
       _DrawableCircle.o \
       _DrawableClipPath.o \
       _DrawableColor.o \
       _DrawableCompositeImage.o \
       _DrawableDashArray.o \
       _DrawableDashOffset.o \
       _DrawableEllipse.o \
       _DrawableFillColor.o \
       _DrawableFillOpacity.o \
       _DrawableFillRule.o \
       _DrawableFont.o \
       _DrawableGravity.o \
       _DrawableLine.o \
       _DrawableMatte.o \
       _DrawableMiterLimit.o \
       _DrawablePath.o \
       _DrawablePoint.o \
       _DrawablePointSize.o \
       _DrawablePolygon.o \
       _DrawablePolyline.o \
       _DrawablePopClipPath.o \
       _DrawablePopGraphicContext.o \
       _DrawablePopPattern.o \
       _DrawablePushClipPath.o \
       _DrawablePushGraphicContext.o \
       _DrawablePushPattern.o \
       _DrawableRectangle.o \
       _DrawableRotation.o \
       _DrawableRoundRectangle.o \
       _DrawableScaling.o \
       _DrawableSkewX.o \
       _DrawableSkewY.o \
       _DrawableStrokeAntialias.o \
       _DrawableStrokeColor.o \
       _DrawableStrokeLineCap.o \
       _DrawableStrokeLineJoin.o \
       _DrawableStrokeOpacity.o \
       _DrawableStrokeWidth.o \
       _DrawableText.o \
       _DrawableTextAntialias.o \
       _DrawableTextDecoration.o \
       _DrawableTextUnderColor.o \
       _DrawableTranslation.o \
       _DrawableViewbox.o \
       _Exception.o \
       _EndianType.o \
       _FillRule.o \
       _FilterTypes.o \
       _Geometry.o \
       _GravityType.o \
       _Image.o \
       _ImageType.o \
       _InterlaceType.o \
       _LineCap.o \
       _LineJoin.o \
       _Montage.o \
       _NoiseType.o \
       _OrientationType.o \
       _PaintMethod.o \
       _PathArcAbs.o \
       _PathArcArgs.o \
       _PathArcRel.o \
       _PathClosePath.o \
       _PathCurvetoAbs.o \
       _PathCurvetoArgs.o \
       _PathCurvetoRel.o \
       _PathLinetoAbs.o \
       _PathLinetoHorizontalAbs.o \
       _PathLinetoHorizontalRel.o \
       _PathLinetoRel.o \
       _PathLinetoVerticalAbs.o \
       _PathLinetoVerticalRel.o \
       _PathMovetoAbs.o \
       _PathMovetoRel.o \
       _PathQuadraticCurvetoAbs.o \
       _PathQuadraticCurvetoArgs.o \
       _PathQuadraticCurvetoRel.o \
       _PathSmoothCurvetoAbs.o \
       _PathSmoothCurvetoRel.o \
       _PathSmoothQuadraticCurvetoAbs.o \
       _PathSmoothQuadraticCurvetoRel.o \
       _Pixels.o \
       _QuantumOperator.o \
       _QuantumType.o \
       _RenderingIntent.o \
       _ResolutionType.o \
       _SparseColorMethod.o \
       _StorageType.o \
       _StretchType.o \
       _StyleType.o \
       _STL.o \
       _TypeMetric.o \
       _VirtualPixelMethod.o \
       _VPath.o \
       _gminfo.o \
       _main.o

.SUFFIXES: .cpp .o

$(SO): $(OBJS)
	g++ $(LIBS) -fPIC -shared -o $(SO) $^

.cpp.o:
	g++ $(FLAGS) $(INCS) -o $@ -c $<

clean:
	rm -rf $(OBJS) $(SO)

