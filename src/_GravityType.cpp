#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Include.h>

using namespace boost::python;


void __GravityType()
{
    enum_< Magick::GravityType >("GravityType")
        .value("ForgetGravity", Magick::ForgetGravity)
        .value("NorthWestGravity", Magick::NorthWestGravity)
        .value("NorthGravity", Magick::NorthGravity)
        .value("NorthEastGravity", Magick::NorthEastGravity)
        .value("WestGravity", Magick::WestGravity)
        .value("CenterGravity", Magick::CenterGravity)
        .value("EastGravity", Magick::EastGravity)
        .value("SouthWestGravity", Magick::SouthWestGravity)
        .value("SouthGravity", Magick::SouthGravity)
        .value("SouthEastGravity", Magick::SouthEastGravity)
        .value("StaticGravity", Magick::StaticGravity)
    ;
}
