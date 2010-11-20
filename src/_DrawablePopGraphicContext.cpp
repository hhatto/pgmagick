#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawablePopGraphicContext_Wrapper: Magick::DrawablePopGraphicContext
{
    Magick_DrawablePopGraphicContext_Wrapper(PyObject* py_self_):
        Magick::DrawablePopGraphicContext(), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawablePopGraphicContext()
{
    class_< Magick::DrawablePopGraphicContext, bases<Magick::DrawableBase>, boost::noncopyable, Magick_DrawablePopGraphicContext_Wrapper >("DrawablePopGraphicContext", init<  >())
    ;
}
