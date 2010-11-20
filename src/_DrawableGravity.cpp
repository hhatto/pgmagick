#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawableGravity_Wrapper: Magick::DrawableGravity
{
    Magick_DrawableGravity_Wrapper(PyObject* py_self_, Magick::GravityType p0):
        Magick::DrawableGravity(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawableGravity()
{
    class_< Magick::DrawableGravity, bases<Magick::DrawableBase>, boost::noncopyable, Magick_DrawableGravity_Wrapper >("DrawableGravity", init< Magick::GravityType >())
        .def("gravity", (void (Magick::DrawableGravity::*)(Magick::GravityType) )&Magick::DrawableGravity::gravity)
        .def("gravity", (Magick::GravityType (Magick::DrawableGravity::*)() const)&Magick::DrawableGravity::gravity)
    ;
}
