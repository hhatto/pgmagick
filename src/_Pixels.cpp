#include <boost/python.hpp>
#include <boost/cstdint.hpp>


#include "_Pixels.h"

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

    class_< Magick::PixelPacket>("PixelPacket", init<Magick::PixelPacket>())
        .def_readwrite("red", &Magick::PixelPacket::red)
        .def_readwrite("green", &Magick::PixelPacket::green)
        .def_readwrite("blue", &Magick::PixelPacket::blue)
        .def_readwrite("opacity", &Magick::PixelPacket::opacity)
    ;

    class_< PixelPacketProxy >("PixelPacketProxy", init< Magick::PixelPacket& >())
        .add_property("red", &PixelPacketProxy::get_red, &PixelPacketProxy::set_red)
        .add_property("green", &PixelPacketProxy::get_green, &PixelPacketProxy::set_green)
        .add_property("blue", &PixelPacketProxy::get_blue, &PixelPacketProxy::set_blue)
        .add_property("opacity", &PixelPacketProxy::get_opacity, &PixelPacketProxy::set_opacity)
    ;

    class_< PixelPacketConstArrayProxy >("PixelPacketConstArrayProxy", no_init)
        .def("__getitem__", &PixelPacketConstArrayProxy::get_item)
        .def("__len__", &PixelPacketConstArrayProxy::size)
    ;

    class_< PixelPacketArrayProxy >("PixelPacketArrayProxy", no_init)
        .def("__getitem__", &PixelPacketArrayProxy::get_item)
        .def("__setitem__", &PixelPacketArrayProxy::set_item)
        .def("__len__", &PixelPacketArrayProxy::size)
    ;
}
