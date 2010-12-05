#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawableEllipse_Wrapper: Magick::DrawableEllipse
{
    Magick_DrawableEllipse_Wrapper(PyObject* py_self_, double p0, double p1, double p2, double p3, double p4, double p5):
        Magick::DrawableEllipse(p0, p1, p2, p3, p4, p5), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawableEllipse()
{
    class_< Magick::DrawableEllipse, bases<Magick::DrawableBase>, boost::noncopyable, Magick_DrawableEllipse_Wrapper >("DrawableEllipse", init< double, double, double, double, double, double >())
        .def("originX", (void (Magick::DrawableEllipse::*)(double) )&Magick::DrawableEllipse::originX)
        .def("originX", (double (Magick::DrawableEllipse::*)() const)&Magick::DrawableEllipse::originX)
        .def("originY", (void (Magick::DrawableEllipse::*)(double) )&Magick::DrawableEllipse::originY)
        .def("originY", (double (Magick::DrawableEllipse::*)() const)&Magick::DrawableEllipse::originY)
        .def("radiusX", (void (Magick::DrawableEllipse::*)(double) )&Magick::DrawableEllipse::radiusX)
        .def("radiusX", (double (Magick::DrawableEllipse::*)() const)&Magick::DrawableEllipse::radiusX)
        .def("radiusY", (void (Magick::DrawableEllipse::*)(double) )&Magick::DrawableEllipse::radiusY)
        .def("radiusY", (double (Magick::DrawableEllipse::*)() const)&Magick::DrawableEllipse::radiusY)
        .def("arcStart", (void (Magick::DrawableEllipse::*)(double) )&Magick::DrawableEllipse::arcStart)
        .def("arcStart", (double (Magick::DrawableEllipse::*)() const)&Magick::DrawableEllipse::arcStart)
        .def("arcEnd", (void (Magick::DrawableEllipse::*)(double) )&Magick::DrawableEllipse::arcEnd)
        .def("arcEnd", (double (Magick::DrawableEllipse::*)() const)&Magick::DrawableEllipse::arcEnd)
    ;
}
