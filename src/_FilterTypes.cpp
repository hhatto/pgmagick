#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Include.h>

using namespace boost::python;


void __FilterTypes()
{
    enum_< Magick::FilterTypes >("FilterTypes")
        .value("UndefinedFilter", Magick::UndefinedFilter)
        .value("PointFilter", Magick::PointFilter)
        .value("BoxFilter", Magick::BoxFilter)
        .value("TriangleFilter", Magick::TriangleFilter)
        .value("HermiteFilter", Magick::HermiteFilter)
        .value("HanningFilter", Magick::HanningFilter)
        .value("HammingFilter", Magick::HammingFilter)
        .value("BlackmanFilter", Magick::BlackmanFilter)
        .value("GaussianFilter", Magick::GaussianFilter)
        .value("QuadraticFilter", Magick::QuadraticFilter)
        .value("CubicFilter", Magick::CubicFilter)
        .value("CatromFilter", Magick::CatromFilter)
        .value("MitchellFilter", Magick::MitchellFilter)
        .value("LanczosFilter", Magick::LanczosFilter)
        .value("BesselFilter", Magick::BesselFilter)
        .value("SincFilter", Magick::SincFilter)
    ;
}
