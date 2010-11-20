#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawableFillOpacity_Wrapper: Magick::DrawableFillOpacity
{
    Magick_DrawableFillOpacity_Wrapper(PyObject* py_self_, double p0):
        Magick::DrawableFillOpacity(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawableFillOpacity()
{
    class_< Magick::DrawableFillOpacity, bases<Magick::DrawableBase>, boost::noncopyable, Magick_DrawableFillOpacity_Wrapper >("DrawableFillOpacity", init< double >())
        .def("opacity", (void (Magick::DrawableFillOpacity::*)(double) )&Magick::DrawableFillOpacity::opacity)
        .def("opacity", (double (Magick::DrawableFillOpacity::*)() const)&Magick::DrawableFillOpacity::opacity)
    ;
}
