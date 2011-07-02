#include <boost/python.hpp>

#include <Magick++/Include.h>

using namespace boost::python;


void __DistortImageMethod()
{
#ifdef PGMAGICK_LIB_IMAGEMAGICK
    enum_< Magick::DistortImageMethod >("DistortImageMethod")
        .value("UndefinedDistortion", Magick::UndefinedDistortion)
        .value("AffineDistortion", Magick::AffineDistortion)
        .value("AffineProjectionDistortion", Magick::AffineProjectionDistortion)
        .value("ScaleRotateTranslateDistortion", Magick::ScaleRotateTranslateDistortion)
        .value("PerspectiveDistortion", Magick::PerspectiveDistortion)
        .value("PerspectiveProjectionDistortion", Magick::PerspectiveProjectionDistortion)
        .value("BilinearDistortion", Magick::BilinearDistortion)
        .value("PolynomialDistortion", Magick::PolynomialDistortion)
        .value("ArcDistortion", Magick::ArcDistortion)
        .value("PolarDistortion", Magick::PolarDistortion)
        .value("DePolarDistortion", Magick::DePolarDistortion)
        .value("BarrelDistortion", Magick::BarrelDistortion)
        .value("BarrelInverseDistortion", Magick::BarrelInverseDistortion)
        .value("ShepardsDistortion", Magick::ShepardsDistortion)
        .value("SentinelDistortion", Magick::SentinelDistortion)
    ;
#endif
}
