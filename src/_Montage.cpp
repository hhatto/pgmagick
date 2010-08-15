#include <boost/python.hpp>

#include <Magick++/Montage.h>

using namespace boost::python;


void __Montage()
{
    class_< Magick::Montage >("Montage", init<  >())
        .def("backgroundColor", (void (Magick::Montage::*)(const Magick::Color&) )&Magick::Montage::backgroundColor)
        .def("backgroundColor", (Magick::Color (Magick::Montage::*)() const)&Magick::Montage::backgroundColor)
    ;
}
