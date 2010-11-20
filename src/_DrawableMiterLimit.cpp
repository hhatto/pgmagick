#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawableMiterLimit_Wrapper: Magick::DrawableMiterLimit
{
    Magick_DrawableMiterLimit_Wrapper(PyObject* py_self_, unsigned int p0):
        Magick::DrawableMiterLimit(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawableMiterLimit()
{
    class_< Magick::DrawableMiterLimit, bases<Magick::DrawableBase>, boost::noncopyable, Magick_DrawableMiterLimit_Wrapper >("DrawableMiterLimit", init< unsigned int >())
        .def("miterlimit", (void (Magick::DrawableMiterLimit::*)(unsigned int) )&Magick::DrawableMiterLimit::miterlimit)
        .def("miterlimit", (unsigned int (Magick::DrawableMiterLimit::*)() const)&Magick::DrawableMiterLimit::miterlimit)
    ;
}
