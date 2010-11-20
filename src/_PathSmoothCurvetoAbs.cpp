#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_PathSmoothCurvetoAbs_Wrapper: Magick::PathSmoothCurvetoAbs
{
    Magick_PathSmoothCurvetoAbs_Wrapper(PyObject* py_self_, const Magick::Coordinate& p0):
        Magick::PathSmoothCurvetoAbs(p0), py_self(py_self_) {}

    Magick_PathSmoothCurvetoAbs_Wrapper(PyObject* py_self_, const Magick::CoordinateList& p0):
        Magick::PathSmoothCurvetoAbs(p0), py_self(py_self_) {}

    Magick_PathSmoothCurvetoAbs_Wrapper(PyObject* py_self_, const Magick::PathSmoothCurvetoAbs& p0):
        Magick::PathSmoothCurvetoAbs(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __PathSmoothCurvetoAbs()
{
    class_< Magick::PathSmoothCurvetoAbs, Magick_PathSmoothCurvetoAbs_Wrapper >("PathSmoothCurvetoAbs", init< const Magick::Coordinate& >())
        .def(init< const Magick::CoordinateList& >())
        .def(init< const Magick::PathSmoothCurvetoAbs& >())
    ;

}
