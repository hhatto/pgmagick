#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Include.h>

using namespace boost::python;


void __RenderingIntent()
{
    enum_< Magick::RenderingIntent >("RenderingIntent")
        .value("UndefinedIntent", Magick::UndefinedIntent)
        .value("SaturationIntent", Magick::SaturationIntent)
        .value("PerceptualIntent", Magick::PerceptualIntent)
        .value("AbsoluteIntent", Magick::AbsoluteIntent)
        .value("RelativeIntent", Magick::RelativeIntent)
    ;
}
