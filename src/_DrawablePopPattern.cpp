#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawablePopPattern_Wrapper: Magick::DrawablePopPattern
{
    Magick_DrawablePopPattern_Wrapper(PyObject* py_self_):
        Magick::DrawablePopPattern(), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawablePopPattern()
{
    class_< Magick::DrawablePopPattern, bases<Magick::DrawableBase>, boost::noncopyable, Magick_DrawablePopPattern_Wrapper >("DrawablePopPattern", init<  >())
    ;
}
