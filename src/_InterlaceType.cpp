#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Include.h>

using namespace boost::python;


void __InterlaceType()
{
    enum_< Magick::InterlaceType >("InterlaceType")
        .value("UndefinedInterlace", Magick::UndefinedInterlace)
        .value("NoInterlace", Magick::NoInterlace)
        .value("LineInterlace", Magick::LineInterlace)
        .value("PlaneInterlace", Magick::PlaneInterlace)
        .value("PartitionInterlace", Magick::PartitionInterlace)
    ;
}
