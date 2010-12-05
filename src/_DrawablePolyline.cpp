#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawablePolyline_Wrapper: Magick::DrawablePolyline
{
    Magick_DrawablePolyline_Wrapper(PyObject* py_self_, const Magick::CoordinateList& p0):
        Magick::DrawablePolyline(p0), py_self(py_self_) {}

    Magick_DrawablePolyline_Wrapper(PyObject* py_self_, const Magick::DrawablePolyline& p0):
        Magick::DrawablePolyline(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawablePolyline()
{
    class_< Magick::DrawablePolyline, bases<Magick::DrawableBase>, Magick_DrawablePolyline_Wrapper >("DrawablePolyline", init< const Magick::CoordinateList& >())
        .def(init< const Magick::DrawablePolyline& >())
    ;
}
