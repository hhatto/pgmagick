#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Include.h>

using namespace boost::python;


void __StorageType()
{
    enum_< Magick::StorageType >("StorageType")
        .value("CharPixel", Magick::CharPixel)
        .value("ShortPixel", Magick::ShortPixel)
        .value("IntegerPixel", Magick::IntegerPixel)
        .value("FloatPixel", Magick::FloatPixel)
        .value("DoublePixel", Magick::DoublePixel)
    ;
}
