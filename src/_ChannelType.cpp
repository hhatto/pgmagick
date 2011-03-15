#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Include.h>

using namespace boost::python;


void __ChannelType()
{
    enum_< Magick::ChannelType >("ChannelType")
        .value("UndefinedChannel", Magick::UndefinedChannel)
        .value("RedChannel", Magick::RedChannel)
        .value("CyanChannel", Magick::CyanChannel)
        .value("GreenChannel", Magick::GreenChannel)
        .value("MagentaChannel", Magick::MagentaChannel)
        .value("BlueChannel", Magick::BlueChannel)
        .value("YellowChannel", Magick::YellowChannel)
        .value("OpacityChannel", Magick::OpacityChannel)
        .value("BlackChannel", Magick::BlackChannel)
        .value("MatteChannel", Magick::MatteChannel)
#ifndef GM_1_1_x
        .value("AllChannels", Magick::AllChannels)
        .value("GrayChannel", Magick::GrayChannel)
#endif
    ;
}
