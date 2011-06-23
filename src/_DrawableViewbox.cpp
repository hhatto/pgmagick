#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Drawable.h>
#include <Magick++.h>

using namespace boost::python;

namespace  {

struct Magick_DrawableViewbox_Wrapper: Magick::DrawableViewbox
{
#ifdef PGMAGICK_LIB_IMAGEMAGICK
    Magick_DrawableViewbox_Wrapper(PyObject* py_self_, ::ssize_t p0, ::ssize_t p1, ::ssize_t p2, ::ssize_t p3):
        Magick::DrawableViewbox(p0, p1, p2, p3), py_self(py_self_) {}
#else
    Magick_DrawableViewbox_Wrapper(PyObject* py_self_, long unsigned int p0, long unsigned int p1, long unsigned int p2, long unsigned int p3):
        Magick::DrawableViewbox(p0, p1, p2, p3), py_self(py_self_) {}
#endif

    PyObject* py_self;
};


}

void __DrawableViewbox()
{
#ifdef PGMAGICK_LIB_IMAGEMAGICK
    class_< Magick::DrawableViewbox, bases<Magick::DrawableBase>, boost::noncopyable, Magick_DrawableViewbox_Wrapper >("DrawableViewbox", init< ::ssize_t, ::ssize_t, ::ssize_t, ::ssize_t >())
        .def("x1", (void (Magick::DrawableViewbox::*)(::ssize_t) )&Magick::DrawableViewbox::x1)
        .def("x1", (::ssize_t (Magick::DrawableViewbox::*)() const)&Magick::DrawableViewbox::x1)
        .def("y1", (void (Magick::DrawableViewbox::*)(::ssize_t) )&Magick::DrawableViewbox::y1)
        .def("y1", (::ssize_t (Magick::DrawableViewbox::*)() const)&Magick::DrawableViewbox::y1)
        .def("x2", (void (Magick::DrawableViewbox::*)(::ssize_t) )&Magick::DrawableViewbox::x2)
        .def("x2", (::ssize_t (Magick::DrawableViewbox::*)() const)&Magick::DrawableViewbox::x2)
        .def("y2", (void (Magick::DrawableViewbox::*)(::ssize_t) )&Magick::DrawableViewbox::y2)
        .def("y2", (::ssize_t (Magick::DrawableViewbox::*)() const)&Magick::DrawableViewbox::y2)
#else
    class_< Magick::DrawableViewbox, bases<Magick::DrawableBase>, boost::noncopyable, Magick_DrawableViewbox_Wrapper >("DrawableViewbox", init< long unsigned int, long unsigned int, long unsigned int, long unsigned int >())
        .def("x1", (void (Magick::DrawableViewbox::*)(unsigned long) )&Magick::DrawableViewbox::x1)
        .def("x1", (unsigned long (Magick::DrawableViewbox::*)() const)&Magick::DrawableViewbox::x1)
        .def("y1", (void (Magick::DrawableViewbox::*)(unsigned long) )&Magick::DrawableViewbox::y1)
        .def("y1", (unsigned long (Magick::DrawableViewbox::*)() const)&Magick::DrawableViewbox::y1)
        .def("x2", (void (Magick::DrawableViewbox::*)(unsigned long) )&Magick::DrawableViewbox::x2)
        .def("x2", (unsigned long (Magick::DrawableViewbox::*)() const)&Magick::DrawableViewbox::x2)
        .def("y2", (void (Magick::DrawableViewbox::*)(unsigned long) )&Magick::DrawableViewbox::y2)
        .def("y2", (unsigned long (Magick::DrawableViewbox::*)() const)&Magick::DrawableViewbox::y2)
#endif
    ;
}

