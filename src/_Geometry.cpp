#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Geometry.h>

using namespace boost::python;


void __Geometry()
{
	class_< Magick::Geometry >("Geometry", init<  >())
        .def(init< unsigned int, unsigned int, optional< unsigned int, unsigned int, bool, bool > >())
        .def(init< const std::string& >())
        .def(init< const char* >())
        .def(init< const Magick::Geometry& >())
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("width", (void (Magick::Geometry::*)(size_t) )&Magick::Geometry::width)
        .def("width", (size_t (Magick::Geometry::*)() const)&Magick::Geometry::width)
        .def("height", (void (Magick::Geometry::*)(size_t) )&Magick::Geometry::height)
        .def("height", (size_t (Magick::Geometry::*)() const)&Magick::Geometry::height)
        .def("xOff", (void (Magick::Geometry::*)(::ssize_t) )&Magick::Geometry::xOff)
        .def("xOff", (::ssize_t (Magick::Geometry::*)() const)&Magick::Geometry::xOff)
        .def("yOff", (void (Magick::Geometry::*)(::ssize_t) )&Magick::Geometry::yOff)
        .def("yOff", (::ssize_t (Magick::Geometry::*)() const)&Magick::Geometry::yOff)
#else
        .def("width", (void (Magick::Geometry::*)(unsigned int) )&Magick::Geometry::width)
        .def("width", (unsigned int (Magick::Geometry::*)() const)&Magick::Geometry::width)
        .def("height", (void (Magick::Geometry::*)(unsigned int) )&Magick::Geometry::height)
        .def("height", (unsigned int (Magick::Geometry::*)() const)&Magick::Geometry::height)
        .def("xOff", (void (Magick::Geometry::*)(unsigned int) )&Magick::Geometry::xOff)
        .def("xOff", (unsigned int (Magick::Geometry::*)() const)&Magick::Geometry::xOff)
        .def("yOff", (void (Magick::Geometry::*)(unsigned int) )&Magick::Geometry::yOff)
        .def("yOff", (unsigned int (Magick::Geometry::*)() const)&Magick::Geometry::yOff)
#endif
        .def("xNegative", (void (Magick::Geometry::*)(bool) )&Magick::Geometry::xNegative)
        .def("xNegative", (bool (Magick::Geometry::*)() const)&Magick::Geometry::xNegative)
        .def("yNegative", (void (Magick::Geometry::*)(bool) )&Magick::Geometry::yNegative)
        .def("yNegative", (bool (Magick::Geometry::*)() const)&Magick::Geometry::yNegative)
        .def("percent", (void (Magick::Geometry::*)(bool) )&Magick::Geometry::percent)
        .def("percent", (bool (Magick::Geometry::*)() const)&Magick::Geometry::percent)
        .def("aspect", (void (Magick::Geometry::*)(bool) )&Magick::Geometry::aspect)
        .def("aspect", (bool (Magick::Geometry::*)() const)&Magick::Geometry::aspect)
        .def("greater", (void (Magick::Geometry::*)(bool) )&Magick::Geometry::greater)
        .def("greater", (bool (Magick::Geometry::*)() const)&Magick::Geometry::greater)
        .def("less", (void (Magick::Geometry::*)(bool) )&Magick::Geometry::less)
        .def("less", (bool (Magick::Geometry::*)() const)&Magick::Geometry::less)
        .def("isValid", (void (Magick::Geometry::*)(bool) )&Magick::Geometry::isValid)
        .def("isValid", (bool (Magick::Geometry::*)() const)&Magick::Geometry::isValid)
        .def( self <= self )
        .def( self == self )
        .def( self > self )
        .def( self != self )
        .def( self < self )
        .def( self >= self )
        .def("to_std_string", &Magick::Geometry::operator std::string)
    ;

    implicitly_convertible<std::string,Magick::Geometry>();
}

