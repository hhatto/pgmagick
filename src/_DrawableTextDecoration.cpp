#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawableTextDecoration_Wrapper: Magick::DrawableTextDecoration
{
    Magick_DrawableTextDecoration_Wrapper(PyObject* py_self_, Magick::DecorationType p0):
        Magick::DrawableTextDecoration(p0), py_self(py_self_) {}

    Magick_DrawableTextDecoration_Wrapper(PyObject* py_self_, const Magick::DrawableTextDecoration& p0):
        Magick::DrawableTextDecoration(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawableTextDecoration()
{
    class_< Magick::DrawableTextDecoration, bases<Magick::DrawableBase>, Magick_DrawableTextDecoration_Wrapper >("DrawableTextDecoration", init< Magick::DecorationType >())
        .def(init< const Magick::DrawableTextDecoration& >())
        .def("decoration", (void (Magick::DrawableTextDecoration::*)(Magick::DecorationType) )&Magick::DrawableTextDecoration::decoration)
        .def("decoration", (Magick::DecorationType (Magick::DrawableTextDecoration::*)() const)&Magick::DrawableTextDecoration::decoration)
    ;
}
