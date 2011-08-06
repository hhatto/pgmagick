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

#ifdef PGMAGICK_LIB_IMAGEMAGICK
    Magick_DrawableDashArray_Wrapper(PyObject* py_self_, const size_t* p0):
#else
    Magick_DrawableDashArray_Wrapper(PyObject* py_self_, const unsigned int* p0):
#endif
        Magick::DrawableDashArray(p0), py_self(py_self_) {}

    Magick_DrawableDashArray_Wrapper(PyObject* py_self_, const Magick::DrawableDashArray& p0):
        Magick::DrawableDashArray(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawableDashArray()
{
    class_< Magick::DrawableDashArray, bases<Magick::DrawableBase>, Magick_DrawableDashArray_Wrapper >("DrawableDashArray", init< const double* >())
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def(init< const size_t* >())
#else
        .def(init< const unsigned int* >())
#endif
        .def(init< const Magick::DrawableDashArray& >())
    ;
}
