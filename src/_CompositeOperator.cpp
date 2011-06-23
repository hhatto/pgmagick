#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Include.h>

using namespace boost::python;


void __CompositeOperator()
{
    enum_< Magick::CompositeOperator >("CompositeOperator")
        .value("AddCompositeOp", Magick::AddCompositeOp)
        .value("AtopCompositeOp", Magick::AtopCompositeOp)
        .value("BumpmapCompositeOp", Magick::BumpmapCompositeOp)
        .value("ClearCompositeOp", Magick::ClearCompositeOp)
        .value("ColorizeCompositeOp", Magick::ColorizeCompositeOp)
        .value("CopyBlueCompositeOp", Magick::CopyBlueCompositeOp)
        .value("CopyCompositeOp", Magick::CopyCompositeOp)
        .value("CopyGreenCompositeOp", Magick::CopyGreenCompositeOp)
        .value("CopyOpacityCompositeOp", Magick::CopyOpacityCompositeOp)
        .value("CopyRedCompositeOp", Magick::CopyRedCompositeOp)
        .value("DarkenCompositeOp", Magick::DarkenCompositeOp)
        .value("DifferenceCompositeOp", Magick::DifferenceCompositeOp)
        .value("DisplaceCompositeOp", Magick::DisplaceCompositeOp)
        .value("DissolveCompositeOp", Magick::DissolveCompositeOp)
        .value("HueCompositeOp", Magick::HueCompositeOp)
        .value("InCompositeOp", Magick::InCompositeOp)
        .value("LightenCompositeOp", Magick::LightenCompositeOp)
        .value("LuminizeCompositeOp", Magick::LuminizeCompositeOp)
        .value("MinusCompositeOp", Magick::MinusCompositeOp)
        .value("ModulateCompositeOp", Magick::ModulateCompositeOp)
        .value("MultiplyCompositeOp", Magick::MultiplyCompositeOp)
        .value("NoCompositeOp", Magick::NoCompositeOp)
        .value("OutCompositeOp", Magick::OutCompositeOp)
        .value("OverCompositeOp", Magick::OverCompositeOp)
        .value("OverlayCompositeOp", Magick::OverlayCompositeOp)
        .value("PlusCompositeOp", Magick::PlusCompositeOp)
        .value("SaturateCompositeOp", Magick::SaturateCompositeOp)
        .value("ScreenCompositeOp", Magick::ScreenCompositeOp)
        .value("SubtractCompositeOp", Magick::SubtractCompositeOp)
        .value("ThresholdCompositeOp", Magick::ThresholdCompositeOp)
        .value("UndefinedCompositeOp", Magick::UndefinedCompositeOp)
        .value("XorCompositeOp", Magick::XorCompositeOp)
        .value("CopyCyanCompositeOp", Magick::CopyCyanCompositeOp)
        .value("CopyMagentaCompositeOp", Magick::CopyMagentaCompositeOp)
        .value("CopyYellowCompositeOp", Magick::CopyYellowCompositeOp)
        .value("CopyBlackCompositeOp", Magick::CopyBlackCompositeOp)
#ifdef PGMAGICK_LIB_GRAPHICSMAGICK_1_3_x
        .value("DivideCompositeOp", Magick::DivideCompositeOp)
#endif
    ;
}
