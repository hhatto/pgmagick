#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_PathLinetoAbs_Wrapper: Magick::PathLinetoAbs
{
    Magick_PathLinetoAbs_Wrapper(PyObject* py_self_, const Magick::Coordinate& p0):
        Magick::PathLinetoAbs(p0), py_self(py_self_) {}

    Magick_PathLinetoAbs_Wrapper(PyObject* py_self_, const Magick::CoordinateList& p0):
        Magick::PathLinetoAbs(p0), py_self(py_self_) {}

    Magick_PathLinetoAbs_Wrapper(PyObject* py_self_, const Magick::PathLinetoAbs& p0):
        Magick::PathLinetoAbs(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __PathLinetoAbs()
{
    class_< Magick::PathLinetoAbs, Magick_PathLinetoAbs_Wrapper >("PathLinetoAbs", init< const Magick::Coordinate& >())
        .def(init< const Magick::CoordinateList& >())
        .def(init< const Magick::PathLinetoAbs& >())
    ;

}
