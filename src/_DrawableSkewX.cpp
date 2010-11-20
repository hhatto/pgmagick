#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawableSkewX_Wrapper: Magick::DrawableSkewX
{
    Magick_DrawableSkewX_Wrapper(PyObject* py_self_, double p0):
        Magick::DrawableSkewX(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawableSkewX()
{
    class_< Magick::DrawableSkewX, bases<Magick::DrawableBase>, boost::noncopyable, Magick_DrawableSkewX_Wrapper >("DrawableSkewX", init< double >())
        .def("angle", (void (Magick::DrawableSkewX::*)(double) )&Magick::DrawableSkewX::angle)
        .def("angle", (double (Magick::DrawableSkewX::*)() const)&Magick::DrawableSkewX::angle)
    ;
}
