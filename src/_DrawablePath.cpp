#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawablePath_Wrapper: Magick::DrawablePath
{
    Magick_DrawablePath_Wrapper(PyObject* py_self_, const Magick::VPathList& p0):
        Magick::DrawablePath(p0), py_self(py_self_) {}

    Magick_DrawablePath_Wrapper(PyObject* py_self_, const Magick::DrawablePath& p0):
        Magick::DrawablePath(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawablePath()
{
    class_< Magick::DrawablePath, bases<Magick::DrawableBase>, Magick_DrawablePath_Wrapper >("DrawablePath", init< const Magick::VPathList& >())
        .def(init< const Magick::DrawablePath& >())
    ;
}
