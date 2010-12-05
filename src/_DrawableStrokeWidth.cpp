#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawableStrokeWidth_Wrapper: Magick::DrawableStrokeWidth
{
    Magick_DrawableStrokeWidth_Wrapper(PyObject* py_self_, double p0):
        Magick::DrawableStrokeWidth(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawableStrokeWidth()
{
    class_< Magick::DrawableStrokeWidth, bases<Magick::DrawableBase>, boost::noncopyable, Magick_DrawableStrokeWidth_Wrapper >("DrawableStrokeWidth", init< double >())
        .def("width", (void (Magick::DrawableStrokeWidth::*)(double) )&Magick::DrawableStrokeWidth::width)
        .def("width", (double (Magick::DrawableStrokeWidth::*)() const)&Magick::DrawableStrokeWidth::width)
    ;
}
