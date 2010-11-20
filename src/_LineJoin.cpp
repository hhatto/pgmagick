#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Include.h>

using namespace boost::python;


void __LineJoin()
{
    enum_< Magick::LineJoin >("LineJoin")
        .value("UndefinedJoin", Magick::UndefinedJoin)
        .value("MiterJoin", Magick::MiterJoin)
        .value("RoundJoin", Magick::RoundJoin)
        .value("BevelJoin", Magick::BevelJoin)
    ;
}
