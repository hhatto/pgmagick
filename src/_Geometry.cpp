
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <Magick++/Geometry.h>

// Module ======================================================================
void __Geometry()

{
	boost::python::class_< Magick::Geometry >("Geometry", boost::python::init<  >())
        .def(boost::python::init< unsigned int, unsigned int, boost::python::optional< unsigned int, unsigned int, bool, bool > >())
        .def(boost::python::init< const std::string& >())
        .def(boost::python::init< const char* >())
        .def(boost::python::init< const Magick::Geometry& >())
        .def("width", (void (Magick::Geometry::*)(size_t) )&Magick::Geometry::width)
        .def("width", (size_t (Magick::Geometry::*)() const)&Magick::Geometry::width)
        .def("height", (void (Magick::Geometry::*)(size_t) )&Magick::Geometry::height)
        .def("height", (size_t (Magick::Geometry::*)() const)&Magick::Geometry::height)
#if 0
        .def("xOff", (void (Magick::Geometry::*)(ssize_t) )&Magick::Geometry::xOff)
        .def("xOff", (ssize_t (Magick::Geometry::*)() const)&Magick::Geometry::xOff)
        .def("yOff", (void (Magick::Geometry::*)(ssize_t) )&Magick::Geometry::yOff)
        .def("yOff", (ssize_t (Magick::Geometry::*)() const)&Magick::Geometry::yOff)
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
        .def( boost::python::self <= boost::python::self )
        .def( boost::python::self == boost::python::self )
        .def( boost::python::self > boost::python::self )
        .def( boost::python::self != boost::python::self )
        .def( boost::python::self < boost::python::self )
        .def( boost::python::self >= boost::python::self )
        .def("to_std_string", &Magick::Geometry::operator std::string)
    ;

boost::python::implicitly_convertible<std::string,Magick::Geometry>();}

