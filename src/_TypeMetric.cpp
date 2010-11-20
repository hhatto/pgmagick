#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/TypeMetric.h>

using namespace boost::python;

void __TypeMetric()
{
    class_< Magick::TypeMetric, boost::noncopyable >("TypeMetric", init<  >())
        .def("ascent", &Magick::TypeMetric::ascent)
        .def("descent", &Magick::TypeMetric::descent)
        .def("textWidth", &Magick::TypeMetric::textWidth)
        .def("textHeight", &Magick::TypeMetric::textHeight)
        .def("maxHorizontalAdvance", &Magick::TypeMetric::maxHorizontalAdvance)
    ;

}
