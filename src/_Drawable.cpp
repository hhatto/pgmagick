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
    class_< Magick::VPathList >("VPathList", init<  >())
        .def(init< const Magick::VPathList& >())
        .def("push_back", &std::list<Magick::VPath>::push_back)
        .def("append", &std::list<Magick::VPath>::push_back)
        .def("pop_back", &std::list<Magick::VPath>::pop_back)
        .def("pop", &std::list<Magick::VPath>::pop_back)
        .def("remove", &std::list<Magick::VPath>::remove)
        .def("reverse", &std::list<Magick::VPath>::reverse)
        .def("count", &std::list<Magick::VPath>::size)
        .def("__len__", &std::list<Magick::VPath>::size)
    ;
    class_< Magick::PathArcArgsList >("PathArcArgsList", init<  >())
        .def(init< const Magick::PathArcArgsList& >())
        .def("push_back", &std::list<Magick::PathArcArgs>::push_back)
        .def("append", &std::list<Magick::PathArcArgs>::push_back)
        .def("pop_back", &std::list<Magick::PathArcArgs>::pop_back)
        .def("pop", &std::list<Magick::PathArcArgs>::pop_back)
        .def("remove", &std::list<Magick::PathArcArgs>::remove)
        .def("reverse", &std::list<Magick::PathArcArgs>::reverse)
        .def("count", &std::list<Magick::PathArcArgs>::size)
        .def("__len__", &std::list<Magick::PathArcArgs>::size)
    ;
    class_< Magick::PathCurveToArgsList >("PathCurveToArgsList", init<  >())
        .def(init< const Magick::PathCurveToArgsList& >())
        .def("push_back", &std::list<Magick::PathCurvetoArgs>::push_back)
        .def("append", &std::list<Magick::PathCurvetoArgs>::push_back)
        .def("pop_back", &std::list<Magick::PathCurvetoArgs>::pop_back)
        .def("pop", &std::list<Magick::PathCurvetoArgs>::pop_back)
        .def("remove", &std::list<Magick::PathCurvetoArgs>::remove)
        .def("reverse", &std::list<Magick::PathCurvetoArgs>::reverse)
        .def("count", &std::list<Magick::PathCurvetoArgs>::size)
        .def("__len__", &std::list<Magick::PathCurvetoArgs>::size)
    ;
    class_< Magick::PathQuadraticCurvetoArgsList >("PathQuadraticCurvetoArgsList", init<  >())
        .def(init< const Magick::PathQuadraticCurvetoArgsList& >())
        .def("push_back", &std::list<Magick::PathQuadraticCurvetoArgs>::push_back)
        .def("append", &std::list<Magick::PathQuadraticCurvetoArgs>::push_back)
        .def("pop_back", &std::list<Magick::PathQuadraticCurvetoArgs>::pop_back)
        .def("pop", &std::list<Magick::PathQuadraticCurvetoArgs>::pop_back)
        .def("remove", &std::list<Magick::PathQuadraticCurvetoArgs>::remove)
        .def("reverse", &std::list<Magick::PathQuadraticCurvetoArgs>::reverse)
        .def("count", &std::list<Magick::PathQuadraticCurvetoArgs>::size)
        .def("__len__", &std::list<Magick::PathQuadraticCurvetoArgs>::size)
    ;
}
