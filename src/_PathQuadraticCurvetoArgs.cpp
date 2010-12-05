#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

void __PathQuadraticCurvetoArgs()
{
    class_< Magick::PathQuadraticCurvetoArgs >("PathQuadraticCurvetoArgs", init<  >())
        .def(init< double, double, double, double >())
        .def(init< const Magick::PathQuadraticCurvetoArgs& >())
        .def("x1", (void (Magick::PathQuadraticCurvetoArgs::*)(double) )&Magick::PathQuadraticCurvetoArgs::x1)
        .def("x1", (double (Magick::PathQuadraticCurvetoArgs::*)() const)&Magick::PathQuadraticCurvetoArgs::x1)
        .def("y1", (void (Magick::PathQuadraticCurvetoArgs::*)(double) )&Magick::PathQuadraticCurvetoArgs::y1)
        .def("y1", (double (Magick::PathQuadraticCurvetoArgs::*)() const)&Magick::PathQuadraticCurvetoArgs::y1)
        .def("x", (void (Magick::PathQuadraticCurvetoArgs::*)(double) )&Magick::PathQuadraticCurvetoArgs::x)
        .def("x", (double (Magick::PathQuadraticCurvetoArgs::*)() const)&Magick::PathQuadraticCurvetoArgs::x)
        .def("y", (void (Magick::PathQuadraticCurvetoArgs::*)(double) )&Magick::PathQuadraticCurvetoArgs::y)
        .def("y", (double (Magick::PathQuadraticCurvetoArgs::*)() const)&Magick::PathQuadraticCurvetoArgs::y)
        .def( self < self )
        .def( self > self )
        .def( self != self )
        .def( self == self )
        .def( self <= self )
        .def( self >= self )
    ;

}
