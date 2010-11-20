#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawableStrokeColor_Wrapper: Magick::DrawableStrokeColor
{
    Magick_DrawableStrokeColor_Wrapper(PyObject* py_self_, const Magick::Color& p0):
        Magick::DrawableStrokeColor(p0), py_self(py_self_) {}

    Magick_DrawableStrokeColor_Wrapper(PyObject* py_self_, const Magick::DrawableStrokeColor& p0):
        Magick::DrawableStrokeColor(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawableStrokeColor()
{
    class_< Magick::DrawableStrokeColor, bases<Magick::DrawableBase>, Magick_DrawableStrokeColor_Wrapper >("DrawableStrokeColor", init< const Magick::Color& >())
        .def(init< const Magick::DrawableStrokeColor& >())
        .def("color", (void (Magick::DrawableStrokeColor::*)(const Magick::Color&) )&Magick::DrawableStrokeColor::color)
        .def("color", (Magick::Color (Magick::DrawableStrokeColor::*)() const)&Magick::DrawableStrokeColor::color)
    ;
}
