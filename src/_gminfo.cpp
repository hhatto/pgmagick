#include <boost/python.hpp>
using namespace boost::python;


#define _LIB_VERSION "1.1.x"
#define _LIB_NAME "GraphicsMagick"
#ifdef PGMAGICK_LIB_GRAPHICSMAGICK_1_3_x
    #undef _LIB_VERSION
    #define _LIB_VERSION "1.3.x"
#endif
#ifdef PGMAGICK_LIB_IMAGEMAGICK
    #undef _LIB_VERSION
    #define _LIB_VERSION "6.x.x"
    #undef _LIB_NAME
    #define _LIB_NAME "ImageMagick"
#endif

const char* get_version(void)
{
    return _LIB_VERSION;
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
