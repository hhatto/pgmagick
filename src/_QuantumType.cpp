#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Include.h>

using namespace boost::python;


void __QuantumType()
{
    enum_< Magick::QuantumType >("QuantumType")
        .value("IndexQuantum", Magick::IndexQuantum)
        .value("GrayQuantum", Magick::GrayQuantum)
        .value("IndexAlphaQuantum", Magick::IndexAlphaQuantum)
        .value("GrayAlphaQuantum", Magick::GrayAlphaQuantum)
        .value("RedQuantum", Magick::RedQuantum)
        .value("CyanQuantum", Magick::CyanQuantum)
        .value("GreenQuantum", Magick::GreenQuantum)
        .value("YellowQuantum", Magick::YellowQuantum)
        .value("BlueQuantum", Magick::BlueQuantum)
        .value("MagentaQuantum", Magick::MagentaQuantum)
        .value("AlphaQuantum", Magick::AlphaQuantum)
        .value("BlackQuantum", Magick::BlackQuantum)
        .value("RGBQuantum", Magick::RGBQuantum)
        .value("RGBAQuantum", Magick::RGBAQuantum)
        .value("CMYKQuantum", Magick::CMYKQuantum)
#ifdef PGMAGICK_LIB_GRAPHICSMAGICK_1_3_x
        .value("CIEYQuantum", Magick::CIEYQuantum)
        .value("CIEXYZQuantum", Magick::CIEXYZQuantum)
#endif
    ;
}
