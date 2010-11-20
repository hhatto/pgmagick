#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_PathQuadraticCurvetoAbs_Wrapper: Magick::PathQuadraticCurvetoAbs
{
    Magick_PathQuadraticCurvetoAbs_Wrapper(PyObject* py_self_, const Magick::PathQuadraticCurvetoArgs& p0):
        Magick::PathQuadraticCurvetoAbs(p0), py_self(py_self_) {}

    Magick_PathQuadraticCurvetoAbs_Wrapper(PyObject* py_self_, const Magick::PathQuadraticCurvetoArgsList& p0):
        Magick::PathQuadraticCurvetoAbs(p0), py_self(py_self_) {}

    Magick_PathQuadraticCurvetoAbs_Wrapper(PyObject* py_self_, const Magick::PathQuadraticCurvetoAbs& p0):
        Magick::PathQuadraticCurvetoAbs(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __PathQuadraticCurvetoAbs()
{
    class_< Magick::PathQuadraticCurvetoAbs, Magick_PathQuadraticCurvetoAbs_Wrapper >("PathQuadraticCurvetoAbs", init< const Magick::PathQuadraticCurvetoArgs& >())
        .def(init< const Magick::PathQuadraticCurvetoArgsList& >())
        .def(init< const Magick::PathQuadraticCurvetoAbs& >())
    ;

}
