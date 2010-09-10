#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>

#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawableViewbox_Wrapper: Magick::DrawableViewbox
{
    Magick_DrawableViewbox_Wrapper(PyObject* py_self_, long unsigned int p0, long unsigned int p1, long unsigned int p2, long unsigned int p3):
        Magick::DrawableViewbox(p0, p1, p2, p3), py_self(py_self_) {}


    PyObject* py_self;
};


}

void __DrawableViewbox()
{
    class_< Magick::DrawableViewbox, bases<Magick::DrawableBase>, boost::noncopyable, Magick_DrawableViewbox_Wrapper >("DrawableViewbox", init< long unsigned int, long unsigned int, long unsigned int, long unsigned int >())
        .def("x1", (void (Magick::DrawableViewbox::*)(unsigned long) )&Magick::DrawableViewbox::x1)
        .def("x1", (unsigned long (Magick::DrawableViewbox::*)() const)&Magick::DrawableViewbox::x1)
        .def("y1", (void (Magick::DrawableViewbox::*)(unsigned long) )&Magick::DrawableViewbox::y1)
        .def("y1", (unsigned long (Magick::DrawableViewbox::*)() const)&Magick::DrawableViewbox::y1)
        .def("x2", (void (Magick::DrawableViewbox::*)(unsigned long) )&Magick::DrawableViewbox::x2)
        .def("x2", (unsigned long (Magick::DrawableViewbox::*)() const)&Magick::DrawableViewbox::x2)
        .def("y2", (void (Magick::DrawableViewbox::*)(unsigned long) )&Magick::DrawableViewbox::y2)
        .def("y2", (unsigned long (Magick::DrawableViewbox::*)() const)&Magick::DrawableViewbox::y2)
    ;
}

