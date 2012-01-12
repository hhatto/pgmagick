import sys
import pgmagick

_EXIF_TAGS = [
    "ImageWidth",
    "ImageLength",
    "BitsPerSample",
    "Compression",
    "PhotometricInterpretation",
    "ImageDescription",
    "Make",
    "Model",
    "StripOffsets",
    "Orientation",
    "SamplesPerPixel",
    "RowsPerStrip",
    "StripByteCounts",
    "XResolution",
    "YResolution",
    "PlanarConfiguration",
    "ResolutionUnit",
    "TransferFunction",
    "CreatorTool",
    "ModifyDate",
    "Artist",
    "WhitePoint",
    "PrimaryChromaticities",
    "JPEGInterchangeFormat",
    "JPEGInterchangeFormatLength",
    "YCbCrCoefficients",
    "YCbCrSubSampling",
    "YCbCrPositioning",
    "ReferenceBlackWhite",
    "Copyright",
    "ExposureTime",
    "FNumber",
    "ExifIFDPointer",
    "ExposureProgram",
    "SpectralSensitivity",
    "GPSInfoIFDPointer",
    "ISOSpeedRatings",
    "OECF",
    "ExifVersion",
    "DateTimeOriginal",
    "MetadataDate",
    "ComponentsConfiguration",
    "CompressedBitsPerPixel",
    "ShutterSpeedValue",
    "ApertureValue",
    "BrightnessValue",
    "ExposureBiasValue",
    "MaxApertureValue",
    "SubjectDistance",
    "MeteringMode",
    "LightSource",
    "Flash",
    "FocalLength",
    "SubjectArea",
    "MakerNote",
    "UserComment",
    "SubSecTime",
    "SubSecTimeOriginal",
    "SubSecTimeDegitized",
    "FlashpixVersion",
    "ColorSpace",
    "PixelXDimension",
    "PixelYDimension",
    "RelatedSoundFile",
    "InteroperabilityIFDPointer",
    "FlashEnergy",
    "SpatialFrequencyResponse",
    "FocalPlaneXResolution",
    "FocalPlaneYResolution",
    "FocalPlaneResolutionUnit",
    "SubjectLocation",
    "ExposureIndex",
    "SensingMethod",
    "FileSource",
    "SceneType",
    "CFAPattern",
    "CustomRendered",
    "ExposureMode",
    "WhiteBalance",
    "DigitalZoomRatio",
    "FocalLengthIn35mmFilm",
    "SceneCaptureType",
    "GainControl",
    "Contrast",
    "Saturation",
    "Sharpness",
    "DeviceSettingDescription",
    "SubjectDistanceRange",
    "0xa420",
    "0xa500",
    "DNGVersion",
    "DNGBackwardVersion",
    "DNGUniqueCameraModel",
    "DNGLocalizedCameraModel",
    "DNGCFAPlaneColor",
    "DNGCFALayout",
    "DNGLinearizationTable",
    "DNGBlackLevelRepeatDim",
    "DNGBlackLevel",
    "DNGBlackLevelDeltaH",
    "DNGBlackLevelDeltaV",
    "DNGWhiteLevel",
    "DNGDefaultscale",
    "DNGDefaultCropOrigin",
    "DNGDefaultCropSize",
    "DNGColorMatrix1",
    "DNGColorMatrix2",
    "DNGCameraCalibration1",
    "DNGCameraCalibration2",
    "DNGReductionMatrix1",
    "DNGReductionMatrix2",
    "DNGAnalogBalance",
    "DNGAsShotNeutral",
    "DNGAsShotWhiteXY",
    "DNGBaselineExposure",
    "DNGBaselineNoise",
    "DNGBaselineSharpness",
    "DNGBayerGreenSplit",
    "DNGLinearResponseLimit",
    "DNGCameraSerialNumber",
    "DNGLensInfo",
    "DNGChromaBlurRadius",
    "DNGAntiAliasStrength",
    "DNGShadowScale",
    "DNGPrivateData",
    "DNGMakerNoteSafety",
    "DNGCalibrationIlluminant1",
    "DNGCalibrationIlluminant2",
    "DNGBestQualityScale",
    "DNGRawDataUniqueID",
    "DNGOriginalRawFileName",
    "DNGOriginalRawFileData",
    "DNGActiveArea",
    "DNGMaskedArea",
    "DNGAsShotICCProfile",
    "DNGAsShotPreProfileMatrix",
    "DNGCurrentICCProfile",
    "DNGCurrentPreProfileMatrix",
    "GPSVersionID",
    "GPSLatitudeRef",
    "GPSLatitude",
    "GPSLongitudeRef",
    "GPSLongitude",
    "GPSAltitudeRef",
    "GPSAltitude",
    "GPSTimeStamp",
    "GPSSatellites",
    "GPSStatus",
    "GPSMessureMode",
    "GPSDOP",
    "GPSSpeedRef",
    "GPSSpeed",
    "GPSTrackRef",
    "GPSTrack",
    "GPSImgDirectionRef",
    "GPSImgDirection",
    "GPSMapDatum",
    "GPSDestLatitudeRef",
    "GPSDestLatitude",
    "GPSDestLongitudeRef",
    "GPSDestLongitude",
    "GPSDestBearingRef",
    "GPSDestBearing",
    "GPSDestDistanceRef",
    "GPSDestDistance",
    "GPSProcessingMethod",
    "GPSAreaInformation",
    "GPSDateStamp",
    "GPSDifferential",
    "InteroperabilityIndex",
    "CRSRawFileName",
    "CRSVersion",
    "CRSWhiteBalance",
    "CRSTemperature",
    "CRSTint",
    "CRSShadowTint",
    "CRSExposure",
    "CRSShadows",
    "CRSBrightness",
    "CRSContrast",
    "CRSSaturation",
    "CRSRedSaturation",
    "CRSGreenSaturation",
    "CRSBlueSaturation",
    "CRSSharpness",
    "CRSLuminanceSmoothing",
    "CRSRedHue",
    "CRSGreenHue",
    "CRSBlueHue",
    "CRSColorNoiseReduction",
    "CRSChromaticAberrationR",
    "CRSChromaticAberrationB",
    "CRSVignetteAmount",
    "CRSLens",
    "CRSSerialNumber",
    "CRSAutoBrightness",
    "CRSAutoShadows",
    "CRSAutoContrast",
    "CRSAutoExposure",
    "OLSpecialMode",
    "OLJpegQuality",
    "OLMacro",
    "OLDigitalZoom",
    "OLSoftwareRelease",
    "OLpictInfo",
    "OLCameraID",
    "OLDataDump",
    "OLFlashMode",
    "OLExposureBias",
    "OLFocusMode",
    "OLFocusDistance",
    "OLZoom",
    "OLMacroFocus",
    "OLSharpness",
    "OLColourMatrix",
    "OLBlackLevel",
    "OLWhiteBalance",
    "OLRedBias",
    "OLBlueBias",
    "OLSerialNumber",
    "OLFlashBias",
    "OLContrast",
    "OLSharpnessFactor",
    "OLColourControl",
    "OLValidBits",
    "OLCoringFilter",
    "OLImageWidth",
    "OLImageHeight",
    "OLCompressionRatio",
    "PXExposureTime",
    "PXFNumber",
    "PXISOSpeed",
    "PXExposureBias",
    "PXWhiteBalance",
    "PXLensID",
    "PXImageTone",
    "EXThumbInfo",
    "EXThumbSize",
    "EXThumbOffset",
    "EXQualityMode",
    "EXImageSize",
    "EXISOSensitivity",
    "EXWhiteBalance",
    "EXFocalLength",
    "EXSaturation",
    "EXContrast",
    "EXSharpness",
    "EXPIM",
    "EXThumbnail",
    "EXWBBias",
    "EXFlash",
    "EXObjectDistance",
    "EXFlashDistance",
    "EXRecordMode",
    "EXSelfTimer",
    "EXQuality",
    "EXFocusMode",
    "EXTimeZone",
    "EXBestshotMode",
    "EXCCDSensitivity",
    "EXColorMode",
    "EXColorEnhance",
    "EXFilter",
    "PXOCaptureMode",
    "PXOQualityLevel",
    "PXOFocusMode",
    "PXOFlashMode",
    "PXOWhiteBalance",
    "PXODigitalZoom",
    "PXOSharpness",
    "PXOContrast",
    "PXOSaturation",
    "PXOISOSpeed",
    "PXOColorMode",
    "PXOTimeZone",
    "PXODaylightSavings",
    "NKISOSetting",
    "NKColorMode",
    "NKQuality",
    "NKWhitebalance",
    "NKSharpness",
    "NKFocusMode",
    "NKFlashSetting",
    "NKFlashMode",
    "NKWhiteBalanceOffset",
    "NKISOselection",
    "NKThumbnailIFDOffset",
    "NKImageAdjustment",
    "NKContrastSetting",
    "NKAdapter",
    "NKLensSetting",
    "NKLensInfo",
    "NKManualFocusDistance",
    "NKDigitalZoom",
    "NKAFFocusPoint",
    "NKShutterMode",
    "NKColorSpace",
    "NKColorOffset",
    "NKNoiseReduction",
    "NKLendID",
    "NKShotCount",
    "NKFinishSetting",
    "NKDigitalImgProg",
    "NKEQuality",
    "NKEColorMode",
    "NKEImageAdjustment",
    "NKECCDSensitivity",
    "NKEWhiteBalance",
    "NKEFocus",
    "NKEDigitalZoom",
    "NKEConverter",
    "MLTMakerNoteVersion",
    "MLTCameraSettingsOld",
    "MLTExposureMode",
    "MLTFlashMode",
    "MLTWhiteBalance",
    "MLTImageSize",
    "MLTImageQuality",
    "MLTDriveMode",
    "MLTMeteringMode",
    "MLTFilmSpeed",
    "MLTShutterSpeed",
    "MLTAperture",
    "MLTMacroMode",
    "MLTDigitalZoom",
    "MLTExposureCompensation",
    "MLTBracketStep",
    "MLTunknown16",
    "MLTIntervalLength",
    "MLTIntervalNumber",
    "MLTFocalLength",
    "MLTFocusDistance",
    "MLTFlashFired",
    "MLTDate",
    "MLTTime",
    "MLTMaxAperture",
    "MLTFileNumberMemory",
    "MLTLastFileNumber",
    "MLTWhiteBalanceRed",
    "MLTWhiteBalanceGreen",
    "MLTWhiteBalanceBlue",
    "MLTSaturation",
    "MLTContrast",
    "MLTSharpness",
    "MLTSubjectProgram",
    "MLTFlashCompensation",
    "MLTISOSetting",
    "MLTCameraModel",
    "MLTIntervalMode",
    "MLTFolderName",
    "MLTColorMode",
    "MLTColorFilter",
    "MLTBWFilter",
    "MLTInternalFlash",
    "MLTBrightnessValue",
    "MLTSpotFocusPointX",
    "MLTSpotFocusPointY",
    "MLTWideFocusZone",
    "MLTFocusMode",
    "MLTFocusArea",
    "MLTDECPosition",
    "MLTComppressImageSize",
    "MLTThumbnail",
    "MLTThumbnailOffset",
    "MLTThumbnailLength",
    "MLTLensID",
    "MLTPIMInformation",
    "MLTCameraSettings",
    "SGSerialID",
    "SGDriveMode",
    "SGImageSize",
    "SGAFMode",
    "SGFocusMode",
    "SGWhiteBalance",
    "SGExposureMode",
    "SGMeteringMode",
    "SGFocalLength",
    "SGColorSpace",
    "SGExposure",
    "SGContrast",
    "SGShadow",
    "SGHighlight",
    "SGSaturation",
    "SGSharpness",
    "SGX3FillLight",
    "SGColorCoordination",
    "SGCustomSettingMode",
    "SGJpegQuality",
    "SGFirmware",
    "SGSoftware",
    "SGAutoBlacket",
    "CNMacroMode",
    "CNSelfTimer",
    "CNFlash",
    "CNDriveMode",
    "CNFocusMode",
    "CNImageSize",
    "CNImageSelect",
    "CNDigitalZoom",
    "CNContrast",
    "CNSaturation",
    "CNSharpness",
    "CNISOSensitive",
    "CNMeteringMode",
    "CNFocusType",
    "CNAFPoint",
    "CNExposurePorgram",
    "CNLensID",
    "CNLensMaximum",
    "CNLensMinimum",
    "CNLensUnit",
    "CNFlashDetailed",
    "CNFocusSetting",
    "CNImageStabilization",
    "CNImageEffect",
    "CNHueBias",
    "CNWhitebalance",
    "CNImageNumber",
    "CNAFPointUsed",
    "CNFlashBias",
    "CNAperture",
    "CNExposure",
    "CNNDFilter",
    "CNImageType",
    "CNFirmware",
    "CNUser",
    "CNSerial",
    "CNNoiseReduction",
    "CNButtunFunction",
    "CNMirrorLockUp",
    "CNShutterStep",
    "CNAFSupliment",
    "CNApexPriority",
    "CNAEFunction",
    "CNShutterSynchro",
    "CNAFStopButton",
    "CNFlashMemLimit",
    "CNMenuPosition",
    "CNSETFunction",
    "CNSensorCleaning",
    "CNColorTemp",
    "CNColorSpace",
    "FJVersion",
    "FJQuality",
    "FJSharpness",
    "FJWhiteBalance",
    "FJColor",
    "FJFlashMode",
    "FJFlashStrength",
    "FJMacro",
    "FJFocusMode",
    "FJSlowSync",
    "FJPictureMode",
    "FJContBlacket",
    "FJBlurWarning",
    "FJFocusWarning",
    "FJAEWarning",
    "KCMode",
]


def _convert_colorobj(input_obj):
    if isinstance(input_obj, (list, tuple)):
        r, g, b = int(input_obj[0]), int(input_obj[1]), int(input_obj[2])
        color = pgmagick.Color(r, g, b)
    elif isinstance(input_obj, str):
        color = pgmagick.Color(input_obj)
    else:
        color = input_obj
        assert isinstance(color, pgmagick.Color)
    return color


def _convert_coordinatelist(input_obj):
    """convert from 'list' or 'tuple' object to pgmagick.CoordinateList.

    :type input_obj: list or tuple
    """
    cdl = pgmagick.CoordinateList()
    for obj in input_obj:
        cdl.append(pgmagick.Coordinate(obj[0], obj[1]))
    return cdl


def _convert_paintmethod(input_obj):
    if isinstance(input_obj, pgmagick.PaintMethod):
        return input_obj
    pm = pgmagick.PaintMethod()
    if input_obj.lower() == 'filltoborder':
        paint_method = pm.FillToBorderMethod
    else:
        paint_method = getattr(pm, "%sMethod" % input_obj.title())
    return paint_method


def _convert_vpathlist(input_obj):
    """convert from 'list' or 'tuple' object to pgmagick.VPathList.

    :type input_obj: list or tuple
    """
    vpl = pgmagick.VPathList()
    for obj in input_obj:
        # FIXME
        obj = pgmagick.PathMovetoAbs(pgmagick.Coordinate(obj[0], obj[1]))
        vpl.append(obj)
    return vpl


class Image(object):

    @property
    def height(self):
        return self.img.rows()

    @property
    def width(self):
        return self.img.columns()

    def __init__(self, filename=None, color=None, *args, **kargs):
        self.img = None
        if sys.version_info >= (3, ) and isinstance(filename, (str)):
            self.img = pgmagick.Image(str(filename))
        elif sys.version_info < (3, ) and isinstance(filename, (unicode, str)):
            self.img = pgmagick.Image(str(filename))
        elif isinstance(filename, (list, tuple)):
            size = filename
            geometry = pgmagick.Geometry(int(size[0]), int(size[1]))
            if isinstance(color, (list, tuple)):
                r, g, b = int(color[0]), int(color[1]), int(color[2])
                color = pgmagick.Color(r, g, b)
                self.img = pgmagick.Image(geometry, color)
            elif isinstance(color, str):
                if color.find('gradient') == 0 or color.find('plasma') == 0:
                    self.img = pgmagick.Image(geometry, pgmagick.Color())
                    self.img.read(color)
                else:
                    color = pgmagick.Color(color)
                    self.img = pgmagick.Image(geometry, color)
            else:
                self.img = pgmagick.Image(geometry, pgmagick.Color())
        else:
            self.img = pgmagick.Image()

    def write(self, filename):
        self.img.write(str(filename))

    # API of Manipulate An Image
    def adaptive_threshold(self, width, height, offset=0):
        # TODO: not implemented
        pass

    def add_noise(self, noise_type):
        # TODO: not implemented
        pass

    def add_noise_channel(self, channel, noise_type):
        # TODO: not implemented
        pass

    def affine_transform(self, affine):
        # TODO: not implemented
        pass

    def annotate(self, string, position=(0, 0), gravity='center', angle=0):
        position = pgmagick.Geometry(int(position[0]), int(position[1]))
        gravity = getattr(pgmagick.GravityType, "%sGravity" % gravity.title())
        self.img.annotate(string, position, gravity, angle)

    def blur(self, radius=0.0, sigma=1.0):
        # TODO: not implemented
        pass

    def blur_channel(self, channel, radius=0.0, sigma=1.0):
        if isinstance(channel, str):
            channel = getattr(pgmagick.ChannelType,
                              "%sChannel" % channel.title())
        self.img.blurChannel(channel, radius, sigma)

    def border(self, geometry=None):
        # TODO: not implemented
        pass

    def channel(self, channel):
        # TODO: not implemented
        pass

    def channel_depth(self, channel, depth=None):
        # TODO: not implemented
        pass

    def charcoal(self, radius=0.0, sigma=1.0):
        # TODO: not implemented
        pass

    def chop(self, geometry):
        # TODO: not implemented
        pass

    def colorize(self, opacity_rgb, color):
        # TODO: not implemented
        pass

    def color_matrix(self, order, color_matrix):
        # TODO: not implemented
        pass

    def comment(self, comment):
        # TODO: not implemented
        pass

    def compare(self, reference):
        # TODO: not implemented
        pass

    def composite(self, composite_img, offset,
                  compose=pgmagick.CompositeOperator.InCompositeOp):
        if isinstance(offset, (list, tuple)):
            x = int(offset[0])
            y = int(offset[1])
            offset = pgmagick.Geometry(x, y)
        elif isinstance(offset, pgmagick.Geometry):
            pass
        elif isinstance(offset, str):   # is gravity (string)
            offset = getattr(pgmagick.GravityType,
                             "%sGravity" % offset.title())
        else:   # is gravity (pgmagick.GravityType)
            pass
        if isinstance(compose, pgmagick.CompositeOperator):
            pass
        elif compose.lower() in ('copyblue', 'copygreen', 'copyopacity',
                                 'copyred', 'copycyan', 'copymagenta',
                                 'copyyellow', 'copyblack'):
            color = compose.lower().split('copy')[1].title()
            compose = getattr(pgmagick.CompositeOperator,
                              "Copy%sCompositeOp" % color)
        else:   # other string
            compose = getattr(pgmagick.CompositeOperator,
                              "%sCompositeOp" % compose.title())
        self.img.composite(composite_img, offset, compose)

    def contrast(self, sharpen):
        # TODO: not implemented
        pass

    def convolve(self, order, kernel):
        # TODO: not implemented
        pass

    def crop(self, *geometry):
        if len(geometry) == 4:
            width, height = geometry[0], geometry[1]
            x, y = geometry[2], geometry[3]
            g = pgmagick.Geometry(x, y, width, height)
        elif isinstance(geometry, pgmagick.Geometry):
            g = geometry
        else:
            raise Exception("not support object", geometry)
        self.img.crop(g)

    def cycle_colormap(self, amount):
        # TODO: not implemented
        pass

    def draw(self, draw_obj):
        if isinstance(draw_obj, (list, tuple)):
            draw = pgmagick.DrawableList()
            for d in draw_obj:
                draw.append(d)
        elif isinstance(draw_obj, Draw):
            draw = draw_obj.drawer
        else:
            draw = draw_obj
        self.img.draw(draw)

    def edge(self, radius=0.0):
        # TODO: not implemented
        pass

    def emboss(self, radius=0.0, sigma=1.0):
        # TODO: not implemented
        pass

    def floodfill_color(self, point, fill_color):
        # TODO: not implemented
        pass

    def floodfill_opacity(self, point, opacity, method):
        # TODO: not implemented
        pass

    def floodfill_texture(self, point, texture):
        # TODO: not implemented
        pass

    def scale(self, size, filter_type=None):
        if isinstance(size, float):
            scaled_height = self.img.rows() * size
            scaled_width = self.img.columns() * size
            size = "%dx%d" % (int(scaled_width), int(scaled_height))
        elif isinstance(size, (list, tuple)):
            scaled_width, scaled_height = int(size[0]), int(size[1])
            size = "%dx%d" % (int(scaled_width), int(scaled_height))
        if filter_type:
            filter_type = getattr(pgmagick.FilterTypes,
                                  "%sFilter" % filter_type.title())
            pgmagick.Image.filterType(self, filter_type)
        geometry = pgmagick.Geometry(size)
        self.img.scale(geometry)

    # API of Set/Get Image
    def font_pointsize(self, point_size=None):
        if point_size:
            point_size = float(point_size)
            self.img.fontPointsize(point_size)
        else:
            return self.img.fontPointsize()

    # extra
    def get_exif_info(self):
        """return exif-tag dict
        """
        _dict = {}
        for tag in _EXIF_TAGS:
            ret = self.img.attribute("EXIF:%s" % tag)
            if ret and ret != 'unknown':
                _dict[tag] = ret
        return _dict


class Draw(object):

    def __init__(self):
        self.drawer = pgmagick.DrawableList()

    def affine(self, sx, sy, rx, ry, tx, ty):
        affine = pgmagick.DrawableAffine(float(sx), float(sy),
                                         float(rx), float(ry),
                                         float(tx), float(ty))
        self.drawer.append(affine)

    def arc(self, start_x, start_y, end_x, end_y, start_degrees, end_degrees):
        arc = pgmagick.DrawableArc(float(start_x), float(start_y),
                                   float(end_x), float(end_y),
                                   float(start_degrees), float(end_degrees))
        self.drawer.append(arc)

    def bezier(self, points):
        """Draw a Bezier-curve.

        :param points: ex.) ((5, 5), (6, 6), (7, 7))
        :type points: list
        """
        coordinates = pgmagick.CoordinateList()
        for point in points:
            x, y = float(point[0]), float(point[1])
            coordinates.append(pgmagick.Coordinate(x, y))
        self.drawer.append(pgmagick.DrawableBezier(coordinates))

    def circle(self, origin_x, origin_y, perim_x, perim_y):
        circle = pgmagick.DrawableCircle(float(origin_x), float(origin_y),
                                         float(perim_x), float(perim_y))
        self.drawer.append(circle)

    def color(self, x, y, paint_method):
        """
        :param paint_method: 'point' or 'replace' or 'floodfill' or
                             'filltoborder' or 'reset'
        :type paint_method: str or pgmagick.PaintMethod
        """
        paint_method = _convert_paintmethod(paint_method)
        color = pgmagick.DrawableColor(x, y, paint_method)
        self.drawer.append(color)

    def composite(self, x, y, width, height, image,
                  op=pgmagick.CompositeOperator.OverCompositeOp):
        # FIXME: unable to composite pgmagick.Image object.
        if width == 0 or height == 0:
            composite = pgmagick.DrawableCompositeImage(x, y, image)
        else:
            composite = pgmagick.DrawableCompositeImage(x, y, width, height,
                                                        image, op)
        self.drawer.append(composite)

    def ellipse(self, org_x, org_y, radius_x, radius_y, arc_start, arc_end):
        """
        :param org_x: origination x axis
        :param org_y: origination y axis
        :param radius_x: radius x axis
        :param radius_y: radius y axis
        :param arc_start: arc start angle
        :param arc_end: arc end angle
        """
        ellipse = pgmagick.DrawableEllipse(float(org_x), float(org_y),
                                           float(radius_x), float(radius_y),
                                           float(arc_start), float(arc_end))
        self.drawer.append(ellipse)

    def fill_color(self, color):
        color = _convert_colorobj(color)
        fill_color = pgmagick.DrawableFillColor(color)
        self.drawer.append(fill_color)

    def fill_rule(self, rule='evenodd'):
        if rule.lower() == 'evenodd':
            fill_rule = pgmagick.FillRule.EvenOddRule
        elif rule.lower() == 'nonzero':
            fill_rule = pgmagick.FillRule.NonZeroRule
        else:
            fill_rule = rule
        fill_rule = pgmagick.DrawableFillRule(fill_rule)
        self.drawer.append(fill_rule)

    def fill_opacity(self, opacity):
        """
        :param opacity: 0.0 ~ 1.0
        """
        opacity = pgmagick.DrawableFillOpacity(float(opacity))
        self.drawer.append(opacity)

    def font(self, family, style='normal', weight=400, stretch='normal'):
        style = getattr(pgmagick.StyleType, "%sStyle" % style.title())
        stretch = stretch.lower()
        if 'condensed' in stretch:
            tmp = stretch.split('condensed')[0]
            stretch = "%sCondensedStretch" % tmp.title()
        elif 'expanded' in stretch:
            tmp = stretch.split('expanded')[0]
            stretch = "%sExpandedStretch" % tmp.title()
        else:
            stretch = "%sStretch" % stretch.title()
        stretch = getattr(pgmagick.StretchType, "%s" % stretch)
        if weight is 'bold':
            weight = 800
        font = pgmagick.DrawableFont(family, style, weight, stretch)
        self.drawer.append(font)

    def gravity(self, gravity_type):
        if isinstance(gravity_type, str):
            gravity = getattr(pgmagick.GravityType,
                              "%sGravity" % gravity_type.title())
        else:
            gravity = gravity_type
        gravity_type = pgmagick.DrawableGravity(gravity)
        self.drawer.append(gravity_type)

    def line(self, start_x, start_y, end_x, end_y):
        line = pgmagick.DrawableLine(start_x, start_y, end_x, end_y)
        self.drawer.append(line)

    def matte(self, x, y, paint_method):
        """
        :param paint_method: 'point' or 'replace' or 'floodfill' or
                             'filltoborder' or 'reset'
        :type paint_method: str or pgmagick.PaintMethod
        """
        paint_method = _convert_paintmethod(paint_method)
        self.drawer.append(pgmagick.DrawableMatte(x, y, paint_method))

    def miterlimit(self, miterlimit):
        # FIXME
        self.drawer.append(pgmagick.DrawableMiterLimit(miterlimit))

    def path(self, vpath):
        # FIXME
        if isinstance(vpath, pgmagick.VPathList):
            vpath = vpath
        elif isinstance(vpath, (list, tuple)):
            vpath = _convert_vpathlist(vpath)
        self.drawer.append(pgmagick.DrawablePath(vpath))

    def point(self, x, y):
        self.drawer.append(pgmagick.DrawablePoint(x, y))

    def pointsize(self, pointsize):
        pointsize = pgmagick.DrawablePointSize(pointsize)
        self.drawer.append(pointsize)

    def polygon(self, coordinates):
        if isinstance(coordinates, pgmagick.CoordinateList):
            obj = coordinates
        elif isinstance(coordinates, (list, tuple)):
            obj = _convert_coordinatelist(coordinates)
        self.drawer.append(pgmagick.DrawablePolygon(obj))

    def polyline(self, coordinates):
        if isinstance(coordinates, pgmagick.CoordinateList):
            obj = coordinates
        elif isinstance(coordinates, (list, tuple)):
            obj = _convert_coordinatelist(coordinates)
        self.drawer.append(pgmagick.DrawablePolyline(obj))

    def rectangle(self, upperleft_x, upperleft_y, lowerright_x, lowerright_y):
        r = pgmagick.DrawableRectangle(upperleft_x, upperleft_y,
                                       lowerright_x, lowerright_y)
        self.drawer.append(r)

    def rotation(self, angle):
        self.drawer.append(pgmagick.DrawableRotation(angle))

    def round_rectangle(self, center_x, center_y,
                        width, height, corner_width, corner_height):
        rr = pgmagick.DrawableRoundRectangle(center_x, center_y,
                                             width, height,
                                             corner_width, corner_height)
        self.drawer.append(rr)

    def scaling(self, x, y):
        """Scaling Draw Object

        :param x: 0.0 ~ 1.0
        :param y: 0.0 ~ 1.0
        """
        self.drawer.append(pgmagick.DrawableScaling(float(x), float(y)))

    def skewx(self, angle):
        self.drawer.append(pgmagick.DrawableSkewX(float(angle)))

    def skewy(self, angle):
        self.drawer.append(pgmagick.DrawableSkewY(float(angle)))

    def stroke_antialias(self, flag=True):
        """stroke antialias

        :param flag: True or False. (default is True)
        :type flag: bool
        """
        antialias = pgmagick.DrawableStrokeAntialias(flag)
        self.drawer.append(antialias)

    def stroke_color(self, color):
        color = _convert_colorobj(color)
        color = pgmagick.DrawableStrokeColor(color)
        self.drawer.append(color)

    def stroke_linecap(self, linecap):
        """set to stroke linecap.

        :param linecap: 'undefined', 'butt', 'round', 'square'
        :type linecap: str
        """
        linecap = getattr(pgmagick.LineCap, "%sCap" % linecap.title())
        linecap = pgmagick.DrawableStrokeLineCap(linecap)
        self.drawer.append(linecap)

    def stroke_linejoin(self, linejoin):
        """set to stroke linejoin.

        :param linejoin: 'undefined', 'miter', 'round', 'bevel'
        :type linejoin: str
        """
        linejoin = getattr(pgmagick.LineJoin, "%sJoin" % linejoin.title())
        linejoin = pgmagick.DrawableStrokeLineJoin(linejoin)
        self.drawer.append(linejoin)

    def stroke_opacity(self, opacity):
        self.drawer.append(pgmagick.DrawableStrokeOpacity(float(opacity)))

    def stroke_width(self, width):
        width = float(width)
        width = pgmagick.DrawableStrokeWidth(width)
        self.drawer.append(width)

    def text(self, x, y, string, encoding=None):
        # TODO: unable encoding
        text = pgmagick.DrawableText(x, y, string)
        self.drawer.append(text)

    def text_antialias(self, flag=True):
        """text antialias

        :param flag: True or False. (default is True)
        :type flag: bool
        """
        antialias = pgmagick.DrawableTextAntialias(flag)
        self.drawer.append(antialias)

    def text_decoration(self, decoration):
        """text decoration

        :param decoration: 'no', 'underline', 'overline', 'linethrough'
        :type decoration: str
        """
        if decoration.lower() == 'linethrough':
            d = pgmagick.DecorationType.LineThroughDecoration
        else:
            decoration_type_string = "%sDecoration" % decoration.title()
            d = getattr(pgmagick.DecorationType, "%s" % decoration_type_string)
        decoration = pgmagick.DrawableTextDecoration(d)
        self.drawer.append(decoration)

    def text_undercolor(self, color):
        color = _convert_colorobj(color)
        undercolor = pgmagick.DrawableTextUnderColor(color)
        self.drawer.append(undercolor)

    def translate(self, x, y):
        self.drawer.append(pgmagick.DrawableTranslation(float(x), float(y)))
