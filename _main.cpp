//#define BOOST_PYTHON_STATIC_LIB
#include <boost/python.hpp>
#include <boost/python/module.hpp>
void __Image();
void __Geometry();
void __FilterTypes();

BOOST_PYTHON_MODULE(_pgmagick)
{
    __Image();
    __Geometry();
    __FilterTypes();
}
