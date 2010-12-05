#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_PathMovetoAbs_Wrapper: Magick::PathMovetoAbs
{
    Magick_PathMovetoAbs_Wrapper(PyObject* py_self_, const Magick::Coordinate& p0):
        Magick::PathMovetoAbs(p0), py_self(py_self_) {}

    Magick_PathMovetoAbs_Wrapper(PyObject* py_self_, const Magick::CoordinateList& p0):
        Magick::PathMovetoAbs(p0), py_self(py_self_) {}

    Magick_PathMovetoAbs_Wrapper(PyObject* py_self_, const Magick::PathMovetoAbs& p0):
        Magick::PathMovetoAbs(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __PathMovetoAbs()
{
    class_< Magick::PathMovetoAbs, Magick_PathMovetoAbs_Wrapper >("PathMovetoAbs", init< const Magick::Coordinate& >())
        .def(init< const Magick::CoordinateList& >())
        .def(init< const Magick::PathMovetoAbs& >())
    ;

}
