#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawableCircle_Wrapper: Magick::DrawableCircle
{
    Magick_DrawableCircle_Wrapper(PyObject* py_self_, double p0, double p1, double p2, double p3):
        Magick::DrawableCircle(p0, p1, p2, p3), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawableCircle()
{
    class_< Magick::DrawableCircle, bases<Magick::DrawableBase>, boost::noncopyable, Magick_DrawableCircle_Wrapper >("DrawableCircle", init< double, double, double, double >())
        .def("originX", (void (Magick::DrawableCircle::*)(double) )&Magick::DrawableCircle::originX)
        .def("originX", (double (Magick::DrawableCircle::*)() const)&Magick::DrawableCircle::originX)
        .def("originY", (void (Magick::DrawableCircle::*)(double) )&Magick::DrawableCircle::originY)
        .def("originY", (double (Magick::DrawableCircle::*)() const)&Magick::DrawableCircle::originY)
        .def("perimX", (void (Magick::DrawableCircle::*)(double) )&Magick::DrawableCircle::perimX)
        .def("perimX", (double (Magick::DrawableCircle::*)() const)&Magick::DrawableCircle::perimX)
        .def("perimY", (void (Magick::DrawableCircle::*)(double) )&Magick::DrawableCircle::perimY)
        .def("perimY", (double (Magick::DrawableCircle::*)() const)&Magick::DrawableCircle::perimY)
    ;
}
