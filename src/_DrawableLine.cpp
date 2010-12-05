#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawableLine_Wrapper: Magick::DrawableLine
{
    Magick_DrawableLine_Wrapper(PyObject* py_self_, double p0, double p1, double p2, double p3):
        Magick::DrawableLine(p0, p1, p2, p3), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawableLine()
{
    class_< Magick::DrawableLine, bases<Magick::DrawableBase>, boost::noncopyable, Magick_DrawableLine_Wrapper >("DrawableLine", init< double, double, double, double >())
        .def("startX", (void (Magick::DrawableLine::*)(double) )&Magick::DrawableLine::startX)
        .def("startX", (double (Magick::DrawableLine::*)() const)&Magick::DrawableLine::startX)
        .def("startY", (void (Magick::DrawableLine::*)(double) )&Magick::DrawableLine::startY)
        .def("startY", (double (Magick::DrawableLine::*)() const)&Magick::DrawableLine::startY)
        .def("endX", (void (Magick::DrawableLine::*)(double) )&Magick::DrawableLine::endX)
        .def("endX", (double (Magick::DrawableLine::*)() const)&Magick::DrawableLine::endX)
        .def("endY", (void (Magick::DrawableLine::*)(double) )&Magick::DrawableLine::endY)
        .def("endY", (double (Magick::DrawableLine::*)() const)&Magick::DrawableLine::endY)
    ;
}
