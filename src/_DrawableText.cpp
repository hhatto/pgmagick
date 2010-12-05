#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawableText_Wrapper: Magick::DrawableText
{
    Magick_DrawableText_Wrapper(PyObject* py_self_, const double p0, const double p1, const std::string& p2):
        Magick::DrawableText(p0, p1, p2), py_self(py_self_) {}

    Magick_DrawableText_Wrapper(PyObject* py_self_, const double p0, const double p1, const std::string& p2, const std::string& p3):
        Magick::DrawableText(p0, p1, p2, p3), py_self(py_self_) {}

    Magick_DrawableText_Wrapper(PyObject* py_self_, const Magick::DrawableText& p0):
        Magick::DrawableText(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawableText()
{
    class_< Magick::DrawableText, bases<Magick::DrawableBase>, Magick_DrawableText_Wrapper >("DrawableText", init< const Magick::DrawableText& >())
        .def(init< const double, const double, const std::string& >())
        .def(init< const double, const double, const std::string&, const std::string& >())
        .def("encoding", &Magick::DrawableText::encoding)
        .def("x", (void (Magick::DrawableText::*)(double) )&Magick::DrawableText::x)
        .def("x", (double (Magick::DrawableText::*)() const)&Magick::DrawableText::x)
        .def("y", (void (Magick::DrawableText::*)(double) )&Magick::DrawableText::y)
        .def("y", (double (Magick::DrawableText::*)() const)&Magick::DrawableText::y)
        .def("text", (void (Magick::DrawableText::*)(const std::string&) )&Magick::DrawableText::text)
        .def("text", (std::string (Magick::DrawableText::*)() const)&Magick::DrawableText::text)
    ;
}
