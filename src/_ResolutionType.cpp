#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Include.h>

using namespace boost::python;


void __ResolutionType()
{
    enum_< Magick::ResolutionType >("ResolutionType")
        .value("UndefinedResolution", Magick::UndefinedResolution)
        .value("PixelsPerInchResolution", Magick::PixelsPerInchResolution)
        .value("PixelsPerCentimeterResolution", Magick::PixelsPerCentimeterResolution)
    ;
}
