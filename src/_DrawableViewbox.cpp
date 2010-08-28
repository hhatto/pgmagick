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
#if 0
    class_< Magick::DrawableViewbox, boost::noncopyable, Magick_DrawableViewbox_Wrapper >("DrawableViewbox", init< long unsigned int, long unsigned int, long unsigned int, long unsigned int >())
        .def("x1", (void (Magick::DrawableViewbox::*)(long size_t) )&Magick::DrawableViewbox::x1)
        .def("x1", (long size_t (Magick::DrawableViewbox::*)() const)&Magick::DrawableViewbox::x1)
        .def("y1", (void (Magick::DrawableViewbox::*)(long size_t) )&Magick::DrawableViewbox::y1)
        .def("y1", (long size_t (Magick::DrawableViewbox::*)() const)&Magick::DrawableViewbox::y1)
        .def("x2", (void (Magick::DrawableViewbox::*)(long size_t) )&Magick::DrawableViewbox::x2)
        .def("x2", (long size_t (Magick::DrawableViewbox::*)() const)&Magick::DrawableViewbox::x2)
        .def("y2", (void (Magick::DrawableViewbox::*)(long size_t) )&Magick::DrawableViewbox::y2)
        .def("y2", (long size_t (Magick::DrawableViewbox::*)() const)&Magick::DrawableViewbox::y2)
    ;
#endif
}

