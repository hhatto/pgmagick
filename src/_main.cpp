#include <boost/python.hpp>
#include <boost/python/module.hpp>

void __Blob();
void __Color();
void __Image();
void __Geometry();
void __FilterTypes();


BOOST_PYTHON_MODULE(_pgmagick)
{
    __Blob();
    __Color();
    __Image();
    __Geometry();
    __FilterTypes();
}
