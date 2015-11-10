#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost;
using namespace boost::python;


void __VPath()
{
    implicitly_convertible< Magick::VPathBase, Magick::VPath >();

    class_< Magick::VPathBase, noncopyable >("VPathBase", no_init)
    ;

    class_< Magick::VPath >("VPath", init<  >())
        .def(init< const Magick::VPathBase& >())
        .def(init< const Magick::VPath& >())
        .def( self == self )
        .def( self != self )
        .def( self > self )
        .def( self < self )
        .def( self >= self )
        .def( self <= self )
    ;
}
