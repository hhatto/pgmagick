#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>

#include <Magick++.h>

using namespace boost;
using namespace boost::python;


void __Drawable()
{
    class_< Magick::DrawableBase, noncopyable >("DrawableBase", no_init)
    ;

    class_< Magick::Drawable >("Drawable", init<  >())
        .def(init< const Magick::DrawableBase& >())
        .def(init< const Magick::Drawable& >())
        .def( self != self )
        .def( self == self )
        .def( self < self )
        .def( self > self )
        .def( self <= self )
        .def( self >= self )
    ;
}
