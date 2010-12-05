#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_PathSmoothQuadraticCurvetoAbs_Wrapper: Magick::PathSmoothQuadraticCurvetoAbs
{
    Magick_PathSmoothQuadraticCurvetoAbs_Wrapper(PyObject* py_self_, const Magick::Coordinate& p0):
        Magick::PathSmoothQuadraticCurvetoAbs(p0), py_self(py_self_) {}

    Magick_PathSmoothQuadraticCurvetoAbs_Wrapper(PyObject* py_self_, const Magick::CoordinateList& p0):
        Magick::PathSmoothQuadraticCurvetoAbs(p0), py_self(py_self_) {}

    Magick_PathSmoothQuadraticCurvetoAbs_Wrapper(PyObject* py_self_, const Magick::PathSmoothQuadraticCurvetoAbs& p0):
        Magick::PathSmoothQuadraticCurvetoAbs(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __PathSmoothQuadraticCurvetoAbs()
{
    class_< Magick::PathSmoothQuadraticCurvetoAbs, Magick_PathSmoothQuadraticCurvetoAbs_Wrapper >("PathSmoothQuadraticCurvetoAbs", init< const Magick::Coordinate& >())
        .def(init< const Magick::CoordinateList& >())
        .def(init< const Magick::PathSmoothQuadraticCurvetoAbs& >())
    ;

}
