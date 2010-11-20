#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_PathLinetoHorizontalRel_Wrapper: Magick::PathLinetoHorizontalRel
{
    Magick_PathLinetoHorizontalRel_Wrapper(PyObject* py_self_, double p0):
        Magick::PathLinetoHorizontalRel(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __PathLinetoHorizontalRel()
{
    class_< Magick::PathLinetoHorizontalRel, boost::noncopyable, Magick_PathLinetoHorizontalRel_Wrapper >("PathLinetoHorizontalRel", init< double >())
        .def("x", (void (Magick::PathLinetoHorizontalRel::*)(double) )&Magick::PathLinetoHorizontalRel::x)
        .def("x", (double (Magick::PathLinetoHorizontalRel::*)() const)&Magick::PathLinetoHorizontalRel::x)
    ;

}
