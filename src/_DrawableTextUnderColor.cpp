#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawableTextUnderColor_Wrapper: Magick::DrawableTextUnderColor
{
    Magick_DrawableTextUnderColor_Wrapper(PyObject* py_self_, const Magick::Color& p0):
        Magick::DrawableTextUnderColor(p0), py_self(py_self_) {}

    Magick_DrawableTextUnderColor_Wrapper(PyObject* py_self_, const Magick::DrawableTextUnderColor& p0):
        Magick::DrawableTextUnderColor(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawableTextUnderColor()
{
    class_< Magick::DrawableTextUnderColor, bases<Magick::DrawableBase>, Magick_DrawableTextUnderColor_Wrapper >("DrawableTextUnderColor", init< const Magick::Color& >())
        .def(init< const Magick::DrawableTextUnderColor& >())
        .def("color", (void (Magick::DrawableTextUnderColor::*)(const Magick::Color&) )&Magick::DrawableTextUnderColor::color)
        .def("color", (Magick::Color (Magick::DrawableTextUnderColor::*)() const)&Magick::DrawableTextUnderColor::color)
    ;
}
