#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_PathSmoothCurvetoRel_Wrapper: Magick::PathSmoothCurvetoRel
{
    Magick_PathSmoothCurvetoRel_Wrapper(PyObject* py_self_, const Magick::Coordinate& p0):
        Magick::PathSmoothCurvetoRel(p0), py_self(py_self_) {}

    Magick_PathSmoothCurvetoRel_Wrapper(PyObject* py_self_, const Magick::CoordinateList& p0):
        Magick::PathSmoothCurvetoRel(p0), py_self(py_self_) {}

    Magick_PathSmoothCurvetoRel_Wrapper(PyObject* py_self_, const Magick::PathSmoothCurvetoRel& p0):
        Magick::PathSmoothCurvetoRel(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __PathSmoothCurvetoRel()
{
    class_< Magick::PathSmoothCurvetoRel, Magick_PathSmoothCurvetoRel_Wrapper >("PathSmoothCurvetoRel", init< const Magick::Coordinate& >())
        .def(init< const Magick::CoordinateList& >())
        .def(init< const Magick::PathSmoothCurvetoRel& >())
    ;

}
