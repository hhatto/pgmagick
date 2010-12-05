#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawableDashOffset_Wrapper: Magick::DrawableDashOffset
{
    Magick_DrawableDashOffset_Wrapper(PyObject* py_self_, const double p0):
        Magick::DrawableDashOffset(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawableDashOffset()
{
    class_< Magick::DrawableDashOffset, bases<Magick::DrawableBase>, boost::noncopyable, Magick_DrawableDashOffset_Wrapper >("DrawableDashOffset", init< const double >())
        .def("offset", (void (Magick::DrawableDashOffset::*)(const double) )&Magick::DrawableDashOffset::offset)
        .def("offset", (double (Magick::DrawableDashOffset::*)() const)&Magick::DrawableDashOffset::offset)
    ;
}
