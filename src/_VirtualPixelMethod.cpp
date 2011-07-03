#include <boost/python.hpp>

#include <Magick++/Include.h>

using namespace boost::python;


void __VirtualPixelMethod()
{
#ifdef PGMAGICK_LIB_IMAGEMAGICK
    enum_< Magick::VirtualPixelMethod >("VirtualPixelMethod")
        .value("UndefinedVirtualPixelMethod", Magick::UndefinedVirtualPixelMethod)
        .value("BackgroundVirtualPixelMethod", Magick::BackgroundVirtualPixelMethod)
        .value("DitherVirtualPixelMethod", Magick::DitherVirtualPixelMethod)
        .value("EdgeVirtualPixelMethod", Magick::EdgeVirtualPixelMethod)
        .value("MirrorVirtualPixelMethod", Magick::MirrorVirtualPixelMethod)
        .value("RandomVirtualPixelMethod", Magick::RandomVirtualPixelMethod)
        .value("TileVirtualPixelMethod", Magick::TileVirtualPixelMethod)
        .value("TransparentVirtualPixelMethod", Magick::TransparentVirtualPixelMethod)
        .value("MaskVirtualPixelMethod", Magick::MaskVirtualPixelMethod)
        .value("BlackVirtualPixelMethod", Magick::BlackVirtualPixelMethod)
        .value("GrayVirtualPixelMethod", Magick::GrayVirtualPixelMethod)
        .value("WhiteVirtualPixelMethod", Magick::WhiteVirtualPixelMethod)
        .value("HorizontalTileVirtualPixelMethod", Magick::HorizontalTileVirtualPixelMethod)
        .value("VerticalTileVirtualPixelMethod", Magick::VerticalTileVirtualPixelMethod)
        .value("HorizontalTileEdgeVirtualPixelMethod", Magick::HorizontalTileEdgeVirtualPixelMethod)
        .value("VerticalTileEdgeVirtualPixelMethod", Magick::VerticalTileEdgeVirtualPixelMethod)
        .value("CheckerTileVirtualPixelMethod", Magick::CheckerTileVirtualPixelMethod)
    ;
#endif
}
