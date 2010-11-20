#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawableSkewY_Wrapper: Magick::DrawableSkewY
{
    Magick_DrawableSkewY_Wrapper(PyObject* py_self_, double p0):
        Magick::DrawableSkewY(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawableSkewY()
{
    class_< Magick::DrawableSkewY, bases<Magick::DrawableBase>, boost::noncopyable, Magick_DrawableSkewY_Wrapper >("DrawableSkewY", init< double >())
        .def("angle", (void (Magick::DrawableSkewY::*)(double) )&Magick::DrawableSkewY::angle)
        .def("angle", (double (Magick::DrawableSkewY::*)() const)&Magick::DrawableSkewY::angle)
    ;
}
