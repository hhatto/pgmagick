#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_PathQuadraticCurvetoRel_Wrapper: Magick::PathQuadraticCurvetoRel
{
    Magick_PathQuadraticCurvetoRel_Wrapper(PyObject* py_self_, const Magick::PathQuadraticCurvetoArgs& p0):
        Magick::PathQuadraticCurvetoRel(p0), py_self(py_self_) {}

    Magick_PathQuadraticCurvetoRel_Wrapper(PyObject* py_self_, const Magick::PathQuadraticCurvetoArgsList& p0):
        Magick::PathQuadraticCurvetoRel(p0), py_self(py_self_) {}

    Magick_PathQuadraticCurvetoRel_Wrapper(PyObject* py_self_, const Magick::PathQuadraticCurvetoRel& p0):
        Magick::PathQuadraticCurvetoRel(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __PathQuadraticCurvetoRel()
{
    class_< Magick::PathQuadraticCurvetoRel, Magick_PathQuadraticCurvetoRel_Wrapper >("PathQuadraticCurvetoRel", init< const Magick::PathQuadraticCurvetoArgs& >())
        .def(init< const Magick::PathQuadraticCurvetoArgsList& >())
        .def(init< const Magick::PathQuadraticCurvetoRel& >())
    ;

}
