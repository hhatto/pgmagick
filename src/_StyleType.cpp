#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Include.h>

using namespace boost::python;


void __StyleType()
{
    enum_< Magick::StyleType >("StyleType")
        .value("NormalStyle", Magick::NormalStyle)
        .value("ItalicStyle", Magick::ItalicStyle)
        .value("ObliqueStyle", Magick::ObliqueStyle)
        .value("AnyStyle", Magick::AnyStyle)
    ;
}
