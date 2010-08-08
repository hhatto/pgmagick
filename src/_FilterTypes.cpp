#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Include.h>

using namespace boost::python;


void __FilterTypes()
{
    enum_< Magick::FilterTypes >("FilterTypes")
        .value("BesselFilter", Magick::BesselFilter)
        .value("QuadraticFilter", Magick::QuadraticFilter)
        .value("CatromFilter", Magick::CatromFilter)
        .value("TriangleFilter", Magick::TriangleFilter)
        .value("SincFilter", Magick::SincFilter)
        .value("BoxFilter", Magick::BoxFilter)
        .value("CubicFilter", Magick::CubicFilter)
        .value("HammingFilter", Magick::HammingFilter)
        .value("LanczosFilter", Magick::LanczosFilter)
        .value("MitchellFilter", Magick::MitchellFilter)
        .value("BlackmanFilter", Magick::BlackmanFilter)
        .value("GaussianFilter", Magick::GaussianFilter)
        .value("HanningFilter", Magick::HanningFilter)
        .value("PointFilter", Magick::PointFilter)
        .value("HermiteFilter", Magick::HermiteFilter)
        .value("UndefinedFilter", Magick::UndefinedFilter)
    ;
}
