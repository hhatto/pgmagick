#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_PathClosePath_Wrapper: Magick::PathClosePath
{
    Magick_PathClosePath_Wrapper(PyObject* py_self_):
        Magick::PathClosePath(), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __PathClosePath()
{
    class_< Magick::PathClosePath, boost::noncopyable, Magick_PathClosePath_Wrapper >("PathClosePath", init<  >())
    ;

}
