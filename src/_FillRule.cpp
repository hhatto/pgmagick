#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Include.h>

using namespace boost::python;


void __FillRule()
{
    enum_< Magick::FillRule >("FillRule")
        .value("UndefinedRule", Magick::UndefinedRule)
        .value("EvenOddRule", Magick::EvenOddRule)
        .value("NonZeroRule", Magick::NonZeroRule)
    ;
}
