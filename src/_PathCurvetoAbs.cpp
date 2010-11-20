#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_PathCurvetoAbs_Wrapper: Magick::PathCurvetoAbs
{
    Magick_PathCurvetoAbs_Wrapper(PyObject* py_self_, const Magick::PathCurvetoArgs& p0):
        Magick::PathCurvetoAbs(p0), py_self(py_self_) {}

    Magick_PathCurvetoAbs_Wrapper(PyObject* py_self_, const Magick::PathCurveToArgsList& p0):
        Magick::PathCurvetoAbs(p0), py_self(py_self_) {}

    Magick_PathCurvetoAbs_Wrapper(PyObject* py_self_, const Magick::PathCurvetoAbs& p0):
        Magick::PathCurvetoAbs(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __PathCurvetoAbs()
{
    class_< Magick::PathCurvetoAbs, Magick_PathCurvetoAbs_Wrapper >("PathCurvetoAbs", init< const Magick::PathCurvetoArgs& >())
        .def(init< const Magick::PathCurveToArgsList& >())
        .def(init< const Magick::PathCurvetoAbs& >())
    ;

}
