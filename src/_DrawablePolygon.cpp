#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawablePolygon_Wrapper: Magick::DrawablePolygon
{
    Magick_DrawablePolygon_Wrapper(PyObject* py_self_, const Magick::CoordinateList& p0):
        Magick::DrawablePolygon(p0), py_self(py_self_) {}

    Magick_DrawablePolygon_Wrapper(PyObject* py_self_, const Magick::DrawablePolygon& p0):
        Magick::DrawablePolygon(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawablePolygon()
{
    class_< Magick::DrawablePolygon, bases<Magick::DrawableBase>, Magick_DrawablePolygon_Wrapper >("DrawablePolygon", init< const Magick::CoordinateList& >())
        .def(init< const Magick::DrawablePolygon& >())
    ;
}
