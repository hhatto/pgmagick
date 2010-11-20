#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawableFillColor_Wrapper: Magick::DrawableFillColor
{
    Magick_DrawableFillColor_Wrapper(PyObject* py_self_, const Magick::Color& p0):
        Magick::DrawableFillColor(p0), py_self(py_self_) {}

    Magick_DrawableFillColor_Wrapper(PyObject* py_self_, const Magick::DrawableFillColor& p0):
        Magick::DrawableFillColor(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawableFillColor()
{
    class_< Magick::DrawableFillColor, bases<Magick::DrawableBase>, Magick_DrawableFillColor_Wrapper >("DrawableFillColor", init< const Magick::Color& >())
        .def(init< const Magick::DrawableFillColor& >())
        .def("color", (void (Magick::DrawableFillColor::*)(const Magick::Color&) )&Magick::DrawableFillColor::color)
        .def("color", (Magick::Color (Magick::DrawableFillColor::*)() const)&Magick::DrawableFillColor::color)
    ;
}
