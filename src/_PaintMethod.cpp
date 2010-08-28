#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Include.h>

using namespace boost::python;


void __PaintMethod()
{
    enum_< Magick::PaintMethod >("PaintMethod")
        .value("PointMethod", Magick::PointMethod)
        .value("ReplaceMethod", Magick::ReplaceMethod)
        .value("FloodfillMethod", Magick::FloodfillMethod)
        .value("FillToBorderMethod", Magick::FillToBorderMethod)
        .value("ResetMethod", Magick::ResetMethod)
    ;
}
