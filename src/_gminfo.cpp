#include <boost/python.hpp>
using namespace boost::python;


#define _LIB_NAME "GraphicsMagick"
#ifndef _LIBRARY_VERSION
    #define _LIBRARY_VERSION "0.0.0"

    #ifdef PGMAGICK_LIB_IMAGEMAGICK
        #undef _LIB_NAME
        #define _LIB_NAME "ImageMagick"
    #endif
#endif

const char* get_version(void)
{
    return _LIBRARY_VERSION;
}
const char* get_library(void)
{
    return _LIB_NAME;
}


void __gminfo()
{
    def("get_version", get_version);
    def("get_library", get_library);
}
