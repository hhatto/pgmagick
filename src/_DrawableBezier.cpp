#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawableBezier_Wrapper: Magick::DrawableBezier
{
    Magick_DrawableBezier_Wrapper(PyObject* py_self_, const Magick::CoordinateList& p0):
        Magick::DrawableBezier(p0), py_self(py_self_) {}

    Magick_DrawableBezier_Wrapper(PyObject* py_self_, const Magick::DrawableBezier& p0):
        Magick::DrawableBezier(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawableBezier()
{
    class_< Magick::DrawableBezier, bases<Magick::DrawableBase>, Magick_DrawableBezier_Wrapper >("DrawableBezier", init< const Magick::CoordinateList& >())
        .def(init< const Magick::DrawableBezier& >())
    ;
}
