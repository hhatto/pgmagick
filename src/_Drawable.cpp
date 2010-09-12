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
        .def("append", &std::list<Magick::Drawable>::push_back)
        .def("pop_back", &std::list<Magick::Drawable>::pop_back)
        .def("pop", &std::list<Magick::Drawable>::pop_back)
        .def("remove", &std::list<Magick::Drawable>::remove)
        .def("reverse", &std::list<Magick::Drawable>::reverse)
        .def("count", &std::list<Magick::Drawable>::size)
        .def("__len__", &std::list<Magick::Drawable>::size)
    ;
    class_< Magick::CoordinateList >("CoordinateList", init<  >())
        .def(init< const Magick::CoordinateList& >())
        .def("push_back", &std::list<Magick::Coordinate>::push_back)
        .def("append", &std::list<Magick::Coordinate>::push_back)
        .def("pop_back", &std::list<Magick::Coordinate>::pop_back)
        .def("pop", &std::list<Magick::Coordinate>::pop_back)
        .def("remove", &std::list<Magick::Coordinate>::remove)
        .def("reverse", &std::list<Magick::Coordinate>::reverse)
        .def("count", &std::list<Magick::Coordinate>::size)
        .def("__len__", &std::list<Magick::Coordinate>::size)
    ;
}
