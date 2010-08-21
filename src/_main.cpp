#include <boost/python.hpp>
#include <boost/python/module.hpp>

void __Blob();
void __Color();
void __CompositeOperator();
void __FilterTypes();
void __Geometry();
void __Image();
void __Montage();
void __Pixels();


BOOST_PYTHON_MODULE(_pgmagick)
{
    __Blob();
    __Color();
    __CompositeOperator();
    __FilterTypes();
    __Geometry();
    __Image();
    __Montage();
    __Pixels();
}
