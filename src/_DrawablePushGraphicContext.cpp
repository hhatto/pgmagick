#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawablePushGraphicContext_Wrapper: Magick::DrawablePushGraphicContext
{
    Magick_DrawablePushGraphicContext_Wrapper(PyObject* py_self_):
        Magick::DrawablePushGraphicContext(), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawablePushGraphicContext()
{
    class_< Magick::DrawablePushGraphicContext, bases<Magick::DrawableBase>, boost::noncopyable, Magick_DrawablePushGraphicContext_Wrapper >("DrawablePushGraphicContext", init<  >())
    ;
}
