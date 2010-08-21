#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Exception.h>

using namespace boost::python;

namespace  {

struct Magick_Exception_Wrapper: Magick::Exception
{
    Magick_Exception_Wrapper(PyObject* py_self_, const std::string& p0):
        Magick::Exception(p0), py_self(py_self_) {}

    Magick_Exception_Wrapper(PyObject* py_self_, const Magick::Exception& p0):
        Magick::Exception(p0), py_self(py_self_) {}

    const char* what() const throw() {
        return call_method< const char* >(py_self, "what");
    }

    const char* default_what() const {
        return Magick::Exception::what();
    }

    PyObject* py_self;
};

}


void __Exception()
{
    class_< Magick::Exception, Magick_Exception_Wrapper >("Exception", init< const std::string& >())
        .def(init< const Magick::Exception& >())
        .def("what", (const char* (Magick::Exception::*)() const throw())&Magick::Exception::what, (const char* (Magick_Exception_Wrapper::*)() const)&Magick_Exception_Wrapper::default_what)
    ;
}
