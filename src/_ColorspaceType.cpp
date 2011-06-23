#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Include.h>

using namespace boost::python;


void __ColorspaceType()
{
    enum_< Magick::ColorspaceType >("ColorspaceType")
        .value("UndefinedColorspace", Magick::UndefinedColorspace)
        .value("RGBColorspace", Magick::RGBColorspace)
        .value("GRAYColorspace", Magick::GRAYColorspace)
        .value("TransparentColorspace", Magick::TransparentColorspace)
        .value("OHTAColorspace", Magick::OHTAColorspace)
        .value("XYZColorspace", Magick::XYZColorspace)
        .value("YCbCrColorspace", Magick::YCbCrColorspace)
        .value("YCCColorspace", Magick::YCCColorspace)
        .value("YIQColorspace", Magick::YIQColorspace)
        .value("YPbPrColorspace", Magick::YPbPrColorspace)
        .value("YUVColorspace", Magick::YUVColorspace)
        .value("CMYKColorspace", Magick::CMYKColorspace)
        .value("sRGBColorspace", Magick::sRGBColorspace)
        .value("HSLColorspace", Magick::HSLColorspace)
        .value("HWBColorspace", Magick::HWBColorspace)
#ifdef PGMAGICK_LIB_GRAPHICSMAGICK_1_3_x
        .value("LABColorspace", Magick::LABColorspace)
        .value("CineonLogRGBColorspace", Magick::CineonLogRGBColorspace)
        .value("Rec601LumaColorspace", Magick::Rec601LumaColorspace)
        .value("Rec709LumaColorspace", Magick::Rec709LumaColorspace)
        .value("Rec709YCbCrColorspace", Magick::Rec709YCbCrColorspace)
#endif
    ;
}
