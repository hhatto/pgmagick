#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawableRectangle_Wrapper: Magick::DrawableRectangle
{
    Magick_DrawableRectangle_Wrapper(PyObject* py_self_, double p0, double p1, double p2, double p3):
        Magick::DrawableRectangle(p0, p1, p2, p3), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawableRectangle()
{
    class_< Magick::DrawableRectangle, bases<Magick::DrawableBase>, boost::noncopyable, Magick_DrawableRectangle_Wrapper >("DrawableRectangle", init< double, double, double, double >())
        .def("upperLeftX", (void (Magick::DrawableRectangle::*)(double) )&Magick::DrawableRectangle::upperLeftX)
        .def("upperLeftX", (double (Magick::DrawableRectangle::*)() const)&Magick::DrawableRectangle::upperLeftX)
        .def("upperLeftY", (void (Magick::DrawableRectangle::*)(double) )&Magick::DrawableRectangle::upperLeftY)
        .def("upperLeftY", (double (Magick::DrawableRectangle::*)() const)&Magick::DrawableRectangle::upperLeftY)
        .def("lowerRightX", (void (Magick::DrawableRectangle::*)(double) )&Magick::DrawableRectangle::lowerRightX)
        .def("lowerRightX", (double (Magick::DrawableRectangle::*)() const)&Magick::DrawableRectangle::lowerRightX)
        .def("lowerRightY", (void (Magick::DrawableRectangle::*)(double) )&Magick::DrawableRectangle::lowerRightY)
        .def("lowerRightY", (double (Magick::DrawableRectangle::*)() const)&Magick::DrawableRectangle::lowerRightY)
    ;
}
