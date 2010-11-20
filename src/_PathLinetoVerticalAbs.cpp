#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_PathLinetoVerticalAbs_Wrapper: Magick::PathLinetoVerticalAbs
{
    Magick_PathLinetoVerticalAbs_Wrapper(PyObject* py_self_, double p0):
        Magick::PathLinetoVerticalAbs(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __PathLinetoVerticalAbs()
{
    class_< Magick::PathLinetoVerticalAbs, boost::noncopyable, Magick_PathLinetoVerticalAbs_Wrapper >("PathLinetoVerticalAbs", init< double >())
        .def("y", (void (Magick::PathLinetoVerticalAbs::*)(double) )&Magick::PathLinetoVerticalAbs::y)
        .def("y", (double (Magick::PathLinetoVerticalAbs::*)() const)&Magick::PathLinetoVerticalAbs::y)
    ;

}
