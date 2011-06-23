#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Include.h>

using namespace boost::python;


void __QuantumOperator()
{
#ifndef PGMAGICK_LIB_IMAGEMAGICK
    enum_< Magick::QuantumOperator >("QuantumOperator")
        .value("AddQuantumOp", Magick::AddQuantumOp)
        .value("AndQuantumOp", Magick::AndQuantumOp)
#ifdef PGMAGICK_LIB_GRAPHICSMAGICK_1_3_x
        .value("AssignQuantumOp", Magick::AssignQuantumOp)
#endif
        .value("DivideQuantumOp", Magick::DivideQuantumOp)
        .value("LShiftQuantumOp", Magick::LShiftQuantumOp)
        .value("MultiplyQuantumOp)", Magick::MultiplyQuantumOp)
        .value("OrQuantumOp", Magick::OrQuantumOp)
        .value("RShiftQuantumOp", Magick::RShiftQuantumOp)
        .value("SubtractQuantumOp", Magick::SubtractQuantumOp)
#ifdef PGMAGICK_LIB_GRAPHICSMAGICK_1_3_x
        .value("ThresholdQuantumOp", Magick::ThresholdQuantumOp)
        .value("ThresholdBlackQuantumOp", Magick::ThresholdBlackQuantumOp)
        .value("ThresholdWhiteQuantumOp", Magick::ThresholdWhiteQuantumOp)
#endif
        .value("XorQuantumOp", Magick::XorQuantumOp)
#ifdef PGMAGICK_LIB_GRAPHICSMAGICK_1_3_x
        .value("NoiseGaussianQuantumOp", Magick::NoiseGaussianQuantumOp)
        .value("NoiseImpulseQuantumOp", Magick::NoiseImpulseQuantumOp)
        .value("NoiseLaplacianQuantumOp", Magick::NoiseLaplacianQuantumOp)
        .value("NoiseMultiplicativeQuantumOp", Magick::NoiseMultiplicativeQuantumOp)
        .value("NoisePoissonQuantumOp", Magick::NoisePoissonQuantumOp)
        .value("NoiseUniformQuantumOp", Magick::NoiseUniformQuantumOp)
        .value("NegateQuantumOp", Magick::NegateQuantumOp)
        .value("GammaQuantumOp", Magick::GammaQuantumOp)
        .value("DepthQuantumOp", Magick::DepthQuantumOp)
        .value("LogQuantumOp", Magick::LogQuantumOp)
        .value("MaxQuantumOp", Magick::MaxQuantumOp)
        .value("MinQuantumOp", Magick::MinQuantumOp)
        .value("PowQuantumOp", Magick::PowQuantumOp)
#endif
#endif
    ;
}
