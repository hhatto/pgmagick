#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawablePopClipPath_Wrapper: Magick::DrawablePopClipPath
{
    Magick_DrawablePopClipPath_Wrapper(PyObject* py_self_):
        Magick::DrawablePopClipPath(), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawablePopClipPath()
{
    class_< Magick::DrawablePopClipPath, bases<Magick::DrawableBase>, boost::noncopyable, Magick_DrawablePopClipPath_Wrapper >("DrawablePopClipPath", init<  >())
    ;
}
