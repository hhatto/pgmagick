#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Include.h>

using namespace boost::python;


void __ImageType()
{
    enum_< Magick::ImageType >("ImageType")
        .value("UndefinedType", Magick::UndefinedType)
        .value("BilevelType", Magick::BilevelType)
        .value("GrayscaleType", Magick::GrayscaleType)
        .value("GrayscaleMatteType", Magick::GrayscaleMatteType)
        .value("PaletteType", Magick::PaletteType)
        .value("PaletteMatteType", Magick::PaletteMatteType)
        .value("TrueColorType", Magick::TrueColorType)
        .value("TrueColorMatteType", Magick::TrueColorMatteType)
        .value("ColorSeparationType", Magick::ColorSeparationType)
        .value("ColorSeparationMatteType", Magick::ColorSeparationMatteType)
        .value("OptimizeType", Magick::OptimizeType)
    ;
}
