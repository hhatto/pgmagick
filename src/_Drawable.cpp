#include <boost/python.hpp>

#include <Magick++/Drawable.h>

#include <Magick++.h>

using namespace boost;
using namespace boost::python;


void __Drawable()
{
    implicitly_convertible< Magick::DrawableBase, Magick::Drawable >();

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

    class_< Magick::DrawableList >("DrawableList", init<  >())
        .def(init< const Magick::DrawableList& >())
        .def("push_back", &std::list<Magick::Drawable>::push_back)
        .def("pop_back", &std::list<Magick::Drawable>::pop_back)
        .def("reverse", &std::list<Magick::Drawable>::reverse)
        .def("__len__", &std::list<Magick::Drawable>::size)
    ;
}
