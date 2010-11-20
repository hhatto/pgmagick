#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawableFont_Wrapper: Magick::DrawableFont
{
    Magick_DrawableFont_Wrapper(PyObject* py_self_, const std::string& p0):
        Magick::DrawableFont(p0), py_self(py_self_) {}

    Magick_DrawableFont_Wrapper(PyObject* py_self_, const std::string& p0, Magick::StyleType p1, const long unsigned int p2, Magick::StretchType p3):
        Magick::DrawableFont(p0, p1, p2, p3), py_self(py_self_) {}

    Magick_DrawableFont_Wrapper(PyObject* py_self_, const Magick::DrawableFont& p0):
        Magick::DrawableFont(p0), py_self(py_self_) {}


    PyObject* py_self;
};


}


void __DrawableFont()
{
    class_< Magick::DrawableFont, bases<Magick::DrawableBase>, Magick_DrawableFont_Wrapper >("DrawableFont", init< const std::string& >())
        .def(init< const std::string&, Magick::StyleType, const long unsigned int, Magick::StretchType >())
        .def(init< const Magick::DrawableFont& >())
        .def("font", (void (Magick::DrawableFont::*)(const std::string&) )&Magick::DrawableFont::font)
        .def("font", (std::string (Magick::DrawableFont::*)() const)&Magick::DrawableFont::font)
    ;
}
