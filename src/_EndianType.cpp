#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Include.h>

using namespace boost::python;


void __EndianType()
{
    enum_< Magick::EndianType >("EndianType")
        .value("UndefinedEndian", Magick::UndefinedEndian)
        .value("LSBEndian", Magick::LSBEndian)
        .value("MSBEndian", Magick::MSBEndian)
    ;
}
