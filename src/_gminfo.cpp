#include <boost/python.hpp>
using namespace boost::python;


#ifdef GM_1_1_x
    std::string version("1.1.x");
#else
    std::string version("1.3.x");
#endif


struct GmInfo
{
};

void __gminfo()
{
    class_<GmInfo>("GmInfo", init<>())
        .def_readonly("version", version)
    ;
}
