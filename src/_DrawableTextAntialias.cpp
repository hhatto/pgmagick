#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawableTextAntialias_Wrapper: Magick::DrawableTextAntialias
{
    Magick_DrawableTextAntialias_Wrapper(PyObject* py_self_, bool p0):
        Magick::DrawableTextAntialias(p0), py_self(py_self_) {}

    Magick_DrawableTextAntialias_Wrapper(PyObject* py_self_, const Magick::DrawableTextAntialias& p0):
        Magick::DrawableTextAntialias(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawableTextAntialias()
{
    class_< Magick::DrawableTextAntialias, bases<Magick::DrawableBase>, Magick_DrawableTextAntialias_Wrapper >("DrawableTextAntialias", init< bool >())
        .def(init< const Magick::DrawableTextAntialias& >())
        .def("flag", (void (Magick::DrawableTextAntialias::*)(bool) )&Magick::DrawableTextAntialias::flag)
        .def("flag", (bool (Magick::DrawableTextAntialias::*)() const)&Magick::DrawableTextAntialias::flag)
    ;
}
