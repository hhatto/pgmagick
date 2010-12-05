#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawableColor_Wrapper: Magick::DrawableColor
{
    Magick_DrawableColor_Wrapper(PyObject* py_self_, double p0, double p1, Magick::PaintMethod p2):
        Magick::DrawableColor(p0, p1, p2), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawableColor()
{
    class_< Magick::DrawableColor, bases<Magick::DrawableBase>, boost::noncopyable, Magick_DrawableColor_Wrapper >("DrawableColor", init< double, double, Magick::PaintMethod >())
        .def("x", (void (Magick::DrawableColor::*)(double) )&Magick::DrawableColor::x)
        .def("x", (double (Magick::DrawableColor::*)() const)&Magick::DrawableColor::x)
        .def("y", (void (Magick::DrawableColor::*)(double) )&Magick::DrawableColor::y)
        .def("y", (double (Magick::DrawableColor::*)() const)&Magick::DrawableColor::y)
        .def("paintMethod", (void (Magick::DrawableColor::*)(Magick::PaintMethod) )&Magick::DrawableColor::paintMethod)
        .def("paintMethod", (Magick::PaintMethod (Magick::DrawableColor::*)() const)&Magick::DrawableColor::paintMethod)
    ;
}
