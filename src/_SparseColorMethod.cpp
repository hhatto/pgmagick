#include <boost/python.hpp>

#include <Magick++/Include.h>

using namespace boost::python;


void __SparseColorMethod()
{
#ifdef PGMAGICK_LIB_IMAGEMAGICK
    enum_< Magick::SparseColorMethod >("SparseColorMethod")
        .value("UndefinedColorInterpolate", Magick::UndefinedColorInterpolate)
        .value("BarycentricColorInterpolate", Magick::BarycentricColorInterpolate)
        .value("BilinearColorInterpolate", Magick::BilinearColorInterpolate)
        .value("PolynomialColorInterpolate", Magick::PolynomialColorInterpolate)
        .value("ShepardsColorInterpolate", Magick::ShepardsColorInterpolate)
        .value("VoronoiColorInterpolate", Magick::VoronoiColorInterpolate)
    ;
#endif
}
