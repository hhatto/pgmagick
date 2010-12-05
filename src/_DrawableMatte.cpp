#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawableMatte_Wrapper: Magick::DrawableMatte
{
    Magick_DrawableMatte_Wrapper(PyObject* py_self_, double p0, double p1, Magick::PaintMethod p2):
        Magick::DrawableMatte(p0, p1, p2), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawableMatte()
{
    class_< Magick::DrawableMatte, bases<Magick::DrawableBase>, boost::noncopyable, Magick_DrawableMatte_Wrapper >("DrawableMatte", init< double, double, Magick::PaintMethod >())
        .def("x", (void (Magick::DrawableMatte::*)(double) )&Magick::DrawableMatte::x)
        .def("x", (double (Magick::DrawableMatte::*)() const)&Magick::DrawableMatte::x)
        .def("y", (void (Magick::DrawableMatte::*)(double) )&Magick::DrawableMatte::y)
        .def("y", (double (Magick::DrawableMatte::*)() const)&Magick::DrawableMatte::y)
        .def("paintMethod", (void (Magick::DrawableMatte::*)(Magick::PaintMethod) )&Magick::DrawableMatte::paintMethod)
        .def("paintMethod", (Magick::PaintMethod (Magick::DrawableMatte::*)() const)&Magick::DrawableMatte::paintMethod)
    ;
}
