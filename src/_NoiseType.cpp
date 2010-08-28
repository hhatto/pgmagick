#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Include.h>

using namespace boost::python;


void __NoiseType()
{
    enum_< Magick::NoiseType >("NoiseType")
        .value("UniformNise", Magick::UniformNoise)
        .value("GaussianNoise", Magick::GaussianNoise)
        .value("MultiplicativeGaussianNoise", Magick::MultiplicativeGaussianNoise)
        .value("ImpulseNoise", Magick::ImpulseNoise)
        .value("LaplacianNoise", Magick::LaplacianNoise)
        .value("PoissonNoise", Magick::PoissonNoise)
    ;
}
