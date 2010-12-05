#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

void __PathCurvetoArgs()
{
    class_< Magick::PathCurvetoArgs >("PathCurvetoArgs", init<  >())
        .def(init< double, double, double, double, double, double >())
        .def(init< const Magick::PathCurvetoArgs& >())
        .def("x1", (void (Magick::PathCurvetoArgs::*)(double) )&Magick::PathCurvetoArgs::x1)
        .def("x1", (double (Magick::PathCurvetoArgs::*)() const)&Magick::PathCurvetoArgs::x1)
        .def("y1", (void (Magick::PathCurvetoArgs::*)(double) )&Magick::PathCurvetoArgs::y1)
        .def("y1", (double (Magick::PathCurvetoArgs::*)() const)&Magick::PathCurvetoArgs::y1)
        .def("x2", (void (Magick::PathCurvetoArgs::*)(double) )&Magick::PathCurvetoArgs::x2)
        .def("x2", (double (Magick::PathCurvetoArgs::*)() const)&Magick::PathCurvetoArgs::x2)
        .def("y2", (void (Magick::PathCurvetoArgs::*)(double) )&Magick::PathCurvetoArgs::y2)
        .def("y2", (double (Magick::PathCurvetoArgs::*)() const)&Magick::PathCurvetoArgs::y2)
        .def("x", (void (Magick::PathCurvetoArgs::*)(double) )&Magick::PathCurvetoArgs::x)
        .def("x", (double (Magick::PathCurvetoArgs::*)() const)&Magick::PathCurvetoArgs::x)
        .def("y", (void (Magick::PathCurvetoArgs::*)(double) )&Magick::PathCurvetoArgs::y)
        .def("y", (double (Magick::PathCurvetoArgs::*)() const)&Magick::PathCurvetoArgs::y)
        .def( self <= self )
        .def( self < self )
        .def( self >= self )
        .def( self != self )
        .def( self > self )
        .def( self == self )
    ;

}
