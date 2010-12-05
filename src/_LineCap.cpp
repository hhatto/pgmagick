#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Include.h>

using namespace boost::python;


void __LineCap()
{
    enum_< Magick::LineCap >("LineCap")
        .value("UndefinedCap", Magick::UndefinedCap)
        .value("ButtCap", Magick::ButtCap)
        .value("RoundCap", Magick::RoundCap)
        .value("SquareCap", Magick::SquareCap)
    ;
}
