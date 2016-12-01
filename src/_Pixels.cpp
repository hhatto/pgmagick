#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Pixels.h>

using namespace boost::python;


void __Pixels()
{
    class_< Magick::Pixels, boost::noncopyable >("Pixels", init< Magick::Image& >())
        .def("sync", &Magick::Pixels::sync)
        .def("x", &Magick::Pixels::x)
        .def("y", &Magick::Pixels::y)
        .def("columns", &Magick::Pixels::columns)
        .def("rows", &Magick::Pixels::rows)
    ;

    class_< Magick::PixelPacket, boost::noncopyable >("PixelPacket", no_init)
        .def_readwrite("red", &Magick::PixelPacket::red)
        .def_readwrite("green", &Magick::PixelPacket::green)
        .def_readwrite("blue", &Magick::PixelPacket::blue)
        .def_readwrite("opacity", &Magick::PixelPacket::opacity)
    ;
}
