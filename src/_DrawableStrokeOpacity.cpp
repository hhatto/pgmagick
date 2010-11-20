#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawableStrokeOpacity_Wrapper: Magick::DrawableStrokeOpacity
{
    Magick_DrawableStrokeOpacity_Wrapper(PyObject* py_self_, double p0):
        Magick::DrawableStrokeOpacity(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawableStrokeOpacity()
{
    class_< Magick::DrawableStrokeOpacity, bases<Magick::DrawableBase>, boost::noncopyable, Magick_DrawableStrokeOpacity_Wrapper >("DrawableStrokeOpacity", init< double >())
        .def("opacity", (void (Magick::DrawableStrokeOpacity::*)(double) )&Magick::DrawableStrokeOpacity::opacity)
        .def("opacity", (double (Magick::DrawableStrokeOpacity::*)() const)&Magick::DrawableStrokeOpacity::opacity)
    ;
}
