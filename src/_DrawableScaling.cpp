#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawableScaling_Wrapper: Magick::DrawableScaling
{
    Magick_DrawableScaling_Wrapper(PyObject* py_self_, double p0, double p1):
        Magick::DrawableScaling(p0, p1), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawableScaling()
{
    class_< Magick::DrawableScaling, bases<Magick::DrawableBase>, boost::noncopyable, Magick_DrawableScaling_Wrapper >("DrawableScaling", init< double, double >())
        .def("x", (void (Magick::DrawableScaling::*)(double) )&Magick::DrawableScaling::x)
        .def("x", (double (Magick::DrawableScaling::*)() const)&Magick::DrawableScaling::x)
        .def("y", (void (Magick::DrawableScaling::*)(double) )&Magick::DrawableScaling::y)
        .def("y", (double (Magick::DrawableScaling::*)() const)&Magick::DrawableScaling::y)
    ;
}
