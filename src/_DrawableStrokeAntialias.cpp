#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawableStrokeAntialias_Wrapper: Magick::DrawableStrokeAntialias
{
    Magick_DrawableStrokeAntialias_Wrapper(PyObject* py_self_, bool p0):
        Magick::DrawableStrokeAntialias(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawableStrokeAntialias()
{
    class_< Magick::DrawableStrokeAntialias, bases<Magick::DrawableBase>, boost::noncopyable, Magick_DrawableStrokeAntialias_Wrapper >("DrawableStrokeAntialias", init< bool >())
        .def("flag", (void (Magick::DrawableStrokeAntialias::*)(bool) )&Magick::DrawableStrokeAntialias::flag)
        .def("flag", (bool (Magick::DrawableStrokeAntialias::*)() const)&Magick::DrawableStrokeAntialias::flag)
    ;
}
