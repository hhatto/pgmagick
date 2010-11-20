#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawableFillRule_Wrapper: Magick::DrawableFillRule
{
    Magick_DrawableFillRule_Wrapper(PyObject* py_self_, const Magick::FillRule p0):
        Magick::DrawableFillRule(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawableFillRule()
{
    class_< Magick::DrawableFillRule, bases<Magick::DrawableBase>, boost::noncopyable, Magick_DrawableFillRule_Wrapper >("DrawableFillRule", init< const Magick::FillRule >())
        .def("fillRule", (void (Magick::DrawableFillRule::*)(const Magick::FillRule) )&Magick::DrawableFillRule::fillRule)
        .def("fillRule", (Magick::FillRule (Magick::DrawableFillRule::*)() const)&Magick::DrawableFillRule::fillRule)
    ;
}
