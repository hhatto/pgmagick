#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>

#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawableDashArray_Wrapper: Magick::DrawableDashArray
{
    Magick_DrawableDashArray_Wrapper(PyObject* py_self_, const double* p0):
        Magick::DrawableDashArray(p0), py_self(py_self_) {}

    Magick_DrawableDashArray_Wrapper(PyObject* py_self_, const size_t* p0):
        Magick::DrawableDashArray(p0), py_self(py_self_) {}

    Magick_DrawableDashArray_Wrapper(PyObject* py_self_, const Magick::DrawableDashArray& p0):
        Magick::DrawableDashArray(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawableDashArray()
{
    class_< Magick::DrawableDashArray, Magick_DrawableDashArray_Wrapper >("DrawableDashArray", init< const double* >())
        .def(init< const size_t* >())
        .def(init< const Magick::DrawableDashArray& >())
    ;
}
