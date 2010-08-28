#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Include.h>

using namespace boost::python;


void __DecorationType()
{
    enum_< Magick::DecorationType >("DecorationType")
        .value("NoDecoration", Magick::NoDecoration)
        .value("UnderlineDecoration", Magick::UnderlineDecoration)
        .value("OverlineDecoration", Magick::OverlineDecoration)
        .value("LineThroughDecoration", Magick::LineThroughDecoration)
    ;
}
