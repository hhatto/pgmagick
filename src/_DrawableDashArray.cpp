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

    Magick_DrawableDashArray_Wrapper(PyObject* py_self_, const unsigned int* p0):
        Magick::DrawableDashArray(p0), py_self(py_self_) {}

    Magick_DrawableDashArray_Wrapper(PyObject* py_self_, const Magick::DrawableDashArray& p0):
        Magick::DrawableDashArray(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawableDashArray()
{
    class_< Magick::DrawableDashArray, bases<Magick::DrawableBase>, Magick_DrawableDashArray_Wrapper >("DrawableDashArray", init< const double* >())
        .def(init< const unsigned int* >())
        .def(init< const Magick::DrawableDashArray& >())
    ;
}
