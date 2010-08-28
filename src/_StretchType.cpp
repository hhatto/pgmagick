#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Include.h>

using namespace boost::python;


void __StretchType()
{
    enum_< Magick::StretchType >("StretchType")
        .value("NormalStretch", Magick::NormalStretch)
        .value("UltraCondensedStretch", Magick::UltraCondensedStretch)
        .value("ExtraCondensedStretch", Magick::ExtraCondensedStretch)
        .value("CondensedStretch", Magick::CondensedStretch)
        .value("SemiCondensedStretch", Magick::SemiCondensedStretch)
        .value("SemiExpandedStretch", Magick::SemiExpandedStretch)
        .value("ExpandedStretch", Magick::ExpandedStretch)
        .value("ExtraExpandedStretch", Magick::ExtraExpandedStretch)
        .value("UltraExpandedStretch", Magick::UltraExpandedStretch)
        .value("AnyStretch", Magick::AnyStretch)
    ;
}
