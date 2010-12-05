#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawableStrokeLineJoin_Wrapper: Magick::DrawableStrokeLineJoin
{
    Magick_DrawableStrokeLineJoin_Wrapper(PyObject* py_self_, Magick::LineJoin p0):
        Magick::DrawableStrokeLineJoin(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawableStrokeLineJoin()
{
    class_< Magick::DrawableStrokeLineJoin, bases<Magick::DrawableBase>, boost::noncopyable, Magick_DrawableStrokeLineJoin_Wrapper >("DrawableStrokeLineJoin", init< Magick::LineJoin >())
        .def("linejoin", (void (Magick::DrawableStrokeLineJoin::*)(Magick::LineJoin) )&Magick::DrawableStrokeLineJoin::linejoin)
        .def("linejoin", (Magick::LineJoin (Magick::DrawableStrokeLineJoin::*)() const)&Magick::DrawableStrokeLineJoin::linejoin)
    ;
}
