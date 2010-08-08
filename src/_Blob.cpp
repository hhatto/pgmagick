#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Blob.h>

using namespace boost::python;

namespace  {
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Magick_Blob_updateNoCopy_overloads_2_3, updateNoCopy, 2, 3)
}

static void update_wrapper(Magick::Blob& blob, const std::string& data) {
    blob.update(data.c_str(),data.size());
}

static std::string get_blob_data(const Magick::Blob& blob) {
    const char* data = static_cast<const char*>(blob.data());
    size_t length = blob.length();
    return std::string(data,data+length);
}


void __Blob()
{
    scope* Magick_Blob_scope = new scope(
    class_< Magick::Blob >("Blob", init<  >())
        .def(init< const void*, size_t >())
        .def(init< const Magick::Blob& >())
        .def("base64", (void (Magick::Blob::*)(const std::string) )&Magick::Blob::base64)
        .def("base64", (std::string (Magick::Blob::*)() )&Magick::Blob::base64)
        .def("update", &update_wrapper)
        .def("updateNoCopy", &Magick::Blob::updateNoCopy, Magick_Blob_updateNoCopy_overloads_2_3())
        .def("length", &Magick::Blob::length)
    );

    enum_< Magick::Blob::Allocator >("Allocator")
        .value("NewAllocator", Magick::Blob::NewAllocator)
        .value("MallocAllocator", Magick::Blob::MallocAllocator)
    ;

    delete Magick_Blob_scope;

    def("get_blob_data", &get_blob_data);
}
