#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawablePushClipPath_Wrapper: Magick::DrawablePushClipPath
{
    Magick_DrawablePushClipPath_Wrapper(PyObject* py_self_, const std::string& p0):
        Magick::DrawablePushClipPath(p0), py_self(py_self_) {}

    Magick_DrawablePushClipPath_Wrapper(PyObject* py_self_, const Magick::DrawablePushClipPath& p0):
        Magick::DrawablePushClipPath(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawablePushClipPath()
{
    class_< Magick::DrawablePushClipPath, bases<Magick::DrawableBase>, Magick_DrawablePushClipPath_Wrapper >("DrawablePushClipPath", init< const std::string& >())
        .def(init< const Magick::DrawablePushClipPath& >())
    ;
}
