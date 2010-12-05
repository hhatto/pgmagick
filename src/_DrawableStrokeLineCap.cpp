#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawableStrokeLineCap_Wrapper: Magick::DrawableStrokeLineCap
{
    Magick_DrawableStrokeLineCap_Wrapper(PyObject* py_self_, Magick::LineCap p0):
        Magick::DrawableStrokeLineCap(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawableStrokeLineCap()
{
    class_< Magick::DrawableStrokeLineCap, bases<Magick::DrawableBase>, boost::noncopyable, Magick_DrawableStrokeLineCap_Wrapper >("DrawableStrokeLineCap", init< Magick::LineCap >())
        .def("linecap", (void (Magick::DrawableStrokeLineCap::*)(Magick::LineCap) )&Magick::DrawableStrokeLineCap::linecap)
        .def("linecap", (Magick::LineCap (Magick::DrawableStrokeLineCap::*)() const)&Magick::DrawableStrokeLineCap::linecap)
    ;
}
