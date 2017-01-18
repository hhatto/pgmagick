#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Blob.h>

using namespace boost::python;

static void updateNoCopy_wrapper(Magick::Blob& blob, std::string& data) {
    // NOTE: this is valid?
    std::string str;
    char* w = new char[data.size() + 1];
    std::copy(str.begin(), str.end(), w);
    w[str.size()] = '\0';
    blob.updateNoCopy(w,data.size(),Magick::Blob::NewAllocator);
}

static void update_wrapper(Magick::Blob& blob, const std::string& data) {
    blob.update(data.c_str(),data.size());
}

#if PY_MAJOR_VERSION >= 3
static object get_blob_data(const Magick::Blob& blob) {
    const char* data = static_cast<const char*>(blob.data());
    size_t length = blob.length();
    return object(handle<>(PyBytes_FromStringAndSize(data, length)));
}
#else
static std::string get_blob_data(const Magick::Blob& blob) {
    const char* data = static_cast<const char*>(blob.data());
    size_t length = blob.length();
    return std::string(data,data+length);
}
#endif


void __Blob()
{
    scope* Magick_Blob_scope = new scope(
    class_< Magick::Blob >("Blob", init<  >())
        .def("__init__", &update_wrapper)       // NOTE: valid?
        .def(init< const Magick::Blob& >())
        .def("base64", (void (Magick::Blob::*)(const std::string) )&Magick::Blob::base64)
        .def("base64", (std::string (Magick::Blob::*)() )&Magick::Blob::base64)
        .def("update", &update_wrapper)
        .def("updateNoCopy", &updateNoCopy_wrapper)
        .def("length", &Magick::Blob::length)
    );

    enum_< Magick::Blob::Allocator >("Allocator")
        .value("NewAllocator", Magick::Blob::NewAllocator)
        .value("MallocAllocator", Magick::Blob::MallocAllocator)
    ;

    delete Magick_Blob_scope;

    def("get_blob_data", &get_blob_data);
}
