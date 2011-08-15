#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Image.h>

using namespace boost::python;

namespace  {
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Magick_Image_adaptiveBlur_overloads_0_2, adaptiveBlur, 0, 2)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Magick_Image_adaptiveThreshold_overloads_2_3, adaptiveThreshold, 2, 3)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Magick_Image_blur_overloads_0_2, blur, 0, 2)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Magick_Image_blurChannel_overloads_1_3, blurChannel, 1, 3)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Magick_Image_border_overloads_0_1, border, 0, 1)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Magick_Image_charcoal_overloads_0_2, charcoal, 0, 2)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Magick_Image_composite_overloads_3_4, composite, 3, 4)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Magick_Image_composite_overloads_2_3, composite, 2, 3)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Magick_Image_distort_overloads_3_4, distort, 3, 4)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Magick_Image_edge_overloads_0_1, edge, 0, 1)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Magick_Image_emboss_overloads_0_2, emboss, 0, 2)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Magick_Image_frame_overloads_0_1, frame, 0, 1)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Magick_Image_frame_overloads_2_4, frame, 2, 4)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Magick_Image_map_overloads_1_2, map, 1, 2)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Magick_Image_medianFilter_overloads_0_1, medianFilter, 0, 1)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Magick_Image_negate_overloads_0_1, negate, 0, 1)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Magick_Image_oilPaint_overloads_0_1, oilPaint, 0, 1)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Magick_Image_quantize_overloads_0_1, quantize, 0, 1)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Magick_Image_raise_overloads_0_2, raise, 0, 2)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Magick_Image_segment_overloads_0_2, segment, 0, 2)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Magick_Image_shade_overloads_0_3, shade, 0, 3)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Magick_Image_sharpen_overloads_0_2, sharpen, 0, 2)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Magick_Image_sharpenChannel_overloads_1_3, sharpenChannel, 1, 3)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Magick_Image_sigmoidalContrast_overloads_2_3, sigmoidalContrast, 2, 3)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Magick_Image_solarize_overloads_0_1, solarize, 0, 1)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Magick_Image_spread_overloads_0_1, spread, 0, 1)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Magick_Image_wave_overloads_0_2, wave, 0, 2)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Magick_Image_signature_overloads_0_1, signature, 0, 1)
}


void __Image()
{
    def("InitializeMagick", Magick::InitializeMagick);
    class_< Magick::Image >("Image", init<  >())
        .def(init< const std::string& >())
        .def(init< const Magick::Geometry&, const Magick::Color& >())
        .def(init< const Magick::Blob& >())
        .def(init< const Magick::Blob&, const Magick::Geometry& >())
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def(init< const Magick::Blob&, const Magick::Geometry&, const size_t >())
        .def(init< const Magick::Blob&, const Magick::Geometry&, const size_t, const std::string& >())
#else
        .def(init< const Magick::Blob&, const Magick::Geometry&, const unsigned int >())
        .def(init< const Magick::Blob&, const Magick::Geometry&, const unsigned int, const std::string& >())
#endif
        .def(init< const Magick::Blob&, const Magick::Geometry&, const std::string& >())
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def(init< const size_t, const size_t, const std::string&, const Magick::StorageType, const char* >())
#else
        .def(init< const unsigned int, const unsigned int, const std::string&, const Magick::StorageType, const char* >())
#endif
        .def(init< const Magick::Image& >())
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("adaptiveBlur", &Magick::Image::adaptiveBlur, Magick_Image_adaptiveBlur_overloads_0_2())
#endif
        .def("adaptiveThreshold", &Magick::Image::adaptiveThreshold, Magick_Image_adaptiveThreshold_overloads_2_3())
        .def("addNoise", &Magick::Image::addNoise)
#ifdef PGMAGICK_LIB_GRAPHICSMAGICK_1_3_x
        .def("addNoiseChannel", &Magick::Image::addNoiseChannel)
#endif
        .def("affineTransform", &Magick::Image::affineTransform)
        .def("annotate", (void (Magick::Image::*)(const std::string&, const Magick::Geometry&) )&Magick::Image::annotate)
        .def("annotate", (void (Magick::Image::*)(const std::string&, const Magick::Geometry&, const Magick::GravityType) )&Magick::Image::annotate)
        .def("annotate", (void (Magick::Image::*)(const std::string&, const Magick::Geometry&, const Magick::GravityType, const double) )&Magick::Image::annotate)
        .def("annotate", (void (Magick::Image::*)(const std::string&, const Magick::GravityType) )&Magick::Image::annotate)
        .def("blur", &Magick::Image::blur, Magick_Image_blur_overloads_0_2())
#ifdef PGMAGICK_LIB_GRAPHICSMAGICK_1_3_x
        .def("blurChannel", &Magick::Image::blurChannel, Magick_Image_blurChannel_overloads_1_3())
#endif
        .def("border", &Magick::Image::border, Magick_Image_border_overloads_0_1())
        .def("channel", &Magick::Image::channel)
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("channelDepth", (void (Magick::Image::*)(const Magick::ChannelType, const size_t) )&Magick::Image::channelDepth)
        .def("channelDepth", (size_t (Magick::Image::*)(const Magick::ChannelType) )&Magick::Image::channelDepth)
#else
        .def("channelDepth", (void (Magick::Image::*)(const Magick::ChannelType, const unsigned int) )&Magick::Image::channelDepth)
        .def("channelDepth", (unsigned int (Magick::Image::*)(const Magick::ChannelType) )&Magick::Image::channelDepth)
#endif
        .def("charcoal", &Magick::Image::charcoal, Magick_Image_charcoal_overloads_0_2())
        .def("chop", &Magick::Image::chop)
        .def("colorize", (void (Magick::Image::*)(const unsigned int, const unsigned int, const unsigned int, const Magick::Color&) )&Magick::Image::colorize)
        .def("colorize", (void (Magick::Image::*)(const unsigned int, const Magick::Color&) )&Magick::Image::colorize)
        .def("comment", (void (Magick::Image::*)(const std::string&) )&Magick::Image::comment)
        .def("compare", &Magick::Image::compare)
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("composite", (void (Magick::Image::*)(const Magick::Image&, const ::ssize_t, const ::ssize_t, const Magick::CompositeOperator))&Magick::Image::composite, Magick_Image_composite_overloads_3_4())
#else
        .def("composite", (void (Magick::Image::*)(const Magick::Image&, const int, const int, const Magick::CompositeOperator))&Magick::Image::composite, Magick_Image_composite_overloads_3_4())
#endif
        .def("composite", (void (Magick::Image::*)(const Magick::Image&, const Magick::Geometry&, Magick::CompositeOperator))&Magick::Image::composite, Magick_Image_composite_overloads_2_3())
        .def("composite", (void (Magick::Image::*)(const Magick::Image&, const Magick::GravityType, Magick::CompositeOperator))&Magick::Image::composite,
             Magick_Image_composite_overloads_2_3())
        .def("contrast", &Magick::Image::contrast)
        .def("convolve", &Magick::Image::convolve)
        .def("crop", &Magick::Image::crop)
        .def("cycleColormap", &Magick::Image::cycleColormap)
        .def("despeckle", &Magick::Image::despeckle)
        .def("display", &Magick::Image::display)
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        // FIXME: not worked
        .def("distort", (void (Magick::Image::*)(const Magick::DistortImageMethod, const size_t, const double*, const bool))&Magick::Image::distort)
#endif
        .def("draw", (void (Magick::Image::*)(const Magick::Drawable&) )&Magick::Image::draw)
        .def("draw", (void (Magick::Image::*)(const std::list<Magick::Drawable,std::allocator<Magick::Drawable> >&) )&Magick::Image::draw)
        .def("edge", &Magick::Image::edge, Magick_Image_edge_overloads_0_1())
        .def("emboss", &Magick::Image::emboss, Magick_Image_emboss_overloads_0_2())
        .def("enhance", &Magick::Image::enhance)
        .def("equalize", &Magick::Image::equalize)
        .def("erase", &Magick::Image::erase)
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("extent", (void (Magick::Image::*)(const Magick::Geometry&))&Magick::Image::extent)
        .def("extent", (void (Magick::Image::*)(const Magick::Geometry&, const Magick::Color&))&Magick::Image::extent)
        .def("extent", (void (Magick::Image::*)(const Magick::Geometry&, const Magick::GravityType))&Magick::Image::extent)
        .def("extent", (void (Magick::Image::*)(const Magick::Geometry&, const Magick::Color&, const Magick::GravityType))&Magick::Image::extent)
#endif
        .def("flip", &Magick::Image::flip)
        .def("floodFillColor", (void (Magick::Image::*)(const Magick::Geometry&, const Magick::Color&) )&Magick::Image::floodFillColor)
        .def("floodFillColor", (void (Magick::Image::*)(const Magick::Geometry&, const Magick::Color&, const Magick::Color&) )&Magick::Image::floodFillColor)
        .def("floodFillOpacity", &Magick::Image::floodFillOpacity)
        .def("floodFillTexture", (void (Magick::Image::*)(const Magick::Geometry&, const Magick::Image&) )&Magick::Image::floodFillTexture)
        .def("floodFillTexture", (void (Magick::Image::*)(const Magick::Geometry&, const Magick::Image&, const Magick::Color&) )&Magick::Image::floodFillTexture)
        .def("flop", &Magick::Image::flop)
        .def("frame", (void (Magick::Image::*)(const Magick::Geometry&) )&Magick::Image::frame, Magick_Image_frame_overloads_0_1())
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("frame", (void (Magick::Image::*)(const size_t, const size_t, const ::ssize_t, const ::ssize_t) )&Magick::Image::frame, Magick_Image_frame_overloads_2_4())
#else
        .def("frame", (void (Magick::Image::*)(const unsigned int, const unsigned int, const int, const int) )&Magick::Image::frame, Magick_Image_frame_overloads_2_4())
#endif
        .def("gamma", (void (Magick::Image::*)(const double) )&Magick::Image::gamma)
        .def("gamma", (void (Magick::Image::*)(const double, const double, const double) )&Magick::Image::gamma)
        .def("gaussianBlur", &Magick::Image::gaussianBlur)
#ifdef PGMAGICK_LIB_GRAPHICSMAGICK_1_3_x
        .def("gaussianBlurChannel", &Magick::Image::gaussianBlurChannel)
        .def("haldClut", &Magick::Image::haldClut)
#endif
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("haldClut", &Magick::Image::haldClut)
#endif
        .def("implode", &Magick::Image::implode)
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("inverseFourierTransform", (void (Magick::Image::*)(const Magick::Image&))&Magick::Image::inverseFourierTransform)
        .def("inverseFourierTransform", (void (Magick::Image::*)(const Magick::Image&, const bool))&Magick::Image::inverseFourierTransform)
#endif
        .def("label", (void (Magick::Image::*)(const std::string&) )&Magick::Image::label)
#ifdef PGMAGICK_LIB_GRAPHICSMAGICK_1_3_x
        .def("level", &Magick::Image::level)
        .def("levelChannel", &Magick::Image::levelChannel)
#endif
        .def("magnify", &Magick::Image::magnify)
        .def("map", &Magick::Image::map, Magick_Image_map_overloads_1_2())
        .def("matteFloodfill", &Magick::Image::matteFloodfill)
        .def("medianFilter", &Magick::Image::medianFilter, Magick_Image_medianFilter_overloads_0_1())
        .def("minify", &Magick::Image::minify)
        .def("modulate", &Magick::Image::modulate)
#ifdef PGMAGICK_LIB_GRAPHICSMAGICK_1_3_x
        .def("motionBlur", &Magick::Image::motionBlur)
#endif
        .def("negate", &Magick::Image::negate, Magick_Image_negate_overloads_0_1())
        .def("normalize", &Magick::Image::normalize)
        .def("oilPaint", &Magick::Image::oilPaint, Magick_Image_oilPaint_overloads_0_1())
        .def("opacity", &Magick::Image::opacity)
        .def("opaque", &Magick::Image::opaque)
        .def("ping", (void (Magick::Image::*)(const std::string&) )&Magick::Image::ping)
        .def("ping", (void (Magick::Image::*)(const Magick::Blob&) )&Magick::Image::ping)
        .def("quantize", &Magick::Image::quantize, Magick_Image_quantize_overloads_0_1())
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("quantumOperator", (void (Magick::Image::*)(const Magick::ChannelType, const Magick::MagickEvaluateOperator, double))&Magick::Image::quantumOperator)
        .def("quantumOperator", (void (Magick::Image::*)(const ::ssize_t, const ::ssize_t, const size_t, const size_t, const Magick::ChannelType, const Magick::MagickEvaluateOperator, const double))&Magick::Image::quantumOperator)
#else
        .def("quantumOperator", (void (Magick::Image::*)(const Magick::ChannelType, const Magick::QuantumOperator, Magick::Quantum))&Magick::Image::quantumOperator)
        .def("quantumOperator", (void (Magick::Image::*)(const int, const int, const unsigned int, const unsigned int, const Magick::ChannelType, const Magick::QuantumOperator, Magick::Quantum))&Magick::Image::quantumOperator)
#endif
        .def("process", &Magick::Image::process)
        .def("raise", &Magick::Image::raise, Magick_Image_raise_overloads_0_2())
#ifdef PGMAGICK_LIB_GRAPHICSMAGICK_1_3_x
        .def("randomThreshold", &Magick::Image::randomThreshold)
        .def("randomThresholdChannel", &Magick::Image::randomThresholdChannel)
#endif
        .def("read", (void (Magick::Image::*)(const std::string&) )&Magick::Image::read)
        .def("read", (void (Magick::Image::*)(const Magick::Geometry&, const std::string&) )&Magick::Image::read)
        .def("read", (void (Magick::Image::*)(const Magick::Blob&) )&Magick::Image::read)
        .def("read", (void (Magick::Image::*)(const Magick::Blob&, const Magick::Geometry&) )&Magick::Image::read)
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("read", (void (Magick::Image::*)(const Magick::Blob&, const Magick::Geometry&, const size_t) )&Magick::Image::read)
        .def("read", (void (Magick::Image::*)(const Magick::Blob&, const Magick::Geometry&, const size_t, const std::string&) )&Magick::Image::read)
#else
        .def("read", (void (Magick::Image::*)(const Magick::Blob&, const Magick::Geometry&, const unsigned int) )&Magick::Image::read)
        .def("read", (void (Magick::Image::*)(const Magick::Blob&, const Magick::Geometry&, const unsigned int, const std::string&) )&Magick::Image::read)
#endif
        .def("read", (void (Magick::Image::*)(const Magick::Blob&, const Magick::Geometry&, const std::string&) )&Magick::Image::read)
        .def("reduceNoise", (void (Magick::Image::*)() )&Magick::Image::reduceNoise)
        .def("reduceNoise", (void (Magick::Image::*)(const double) )&Magick::Image::reduceNoise)
        .def("roll", (void (Magick::Image::*)(const Magick::Geometry&) )&Magick::Image::roll)
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("roll", (void (Magick::Image::*)(const size_t, const size_t) )&Magick::Image::roll)
#else
        .def("roll", (void (Magick::Image::*)(const unsigned int, const unsigned int) )&Magick::Image::roll)
#endif
        .def("rotate", &Magick::Image::rotate)
        .def("sample", &Magick::Image::sample)
        .def("scale", &Magick::Image::scale)
        .def("segment", &Magick::Image::segment, Magick_Image_segment_overloads_0_2())
        .def("shade", &Magick::Image::shade, Magick_Image_shade_overloads_0_3())
        .def("sharpen", &Magick::Image::sharpen, Magick_Image_sharpen_overloads_0_2())
#ifdef PGMAGICK_LIB_GRAPHICSMAGICK_1_3_x
        .def("sharpenChannel", &Magick::Image::sharpenChannel, Magick_Image_sharpenChannel_overloads_1_3())
#endif
        .def("shave", &Magick::Image::shave)
        .def("shear", &Magick::Image::shear)
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("sigmoidalContrast", &Magick::Image::sigmoidalContrast, Magick_Image_sigmoidalContrast_overloads_2_3())
#endif
        .def("solarize", &Magick::Image::solarize, Magick_Image_solarize_overloads_0_1())
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("splice", &Magick::Image::splice)
#endif
        .def("spread", &Magick::Image::spread, Magick_Image_spread_overloads_0_1())
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        // FIXME: not worked
        .def("sparseColor", &Magick::Image::sparseColor)
#endif
        .def("stegano", &Magick::Image::stegano)
        .def("stereo", &Magick::Image::stereo)
        .def("swirl", &Magick::Image::swirl)
        .def("texture", &Magick::Image::texture)
        .def("threshold", &Magick::Image::threshold)
        .def("transform", (void (Magick::Image::*)(const Magick::Geometry&) )&Magick::Image::transform)
        .def("transform", (void (Magick::Image::*)(const Magick::Geometry&, const Magick::Geometry&) )&Magick::Image::transform)
        .def("transparent", &Magick::Image::transparent)
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("transparentChroma", &Magick::Image::transparentChroma)
#endif
        .def("trim", &Magick::Image::trim)
        .def("type", (void (Magick::Image::*)(const Magick::ImageType))&Magick::Image::type)
        .def("unsharpmask", &Magick::Image::unsharpmask)
#ifdef PGMAGICK_LIB_GRAPHICSMAGICK_1_3_x
        .def("unsharpmaskChannel", &Magick::Image::unsharpmaskChannel)
#endif
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("unsharpmaskChannel", &Magick::Image::unsharpmaskChannel)
#endif
        .def("wave", &Magick::Image::wave, Magick_Image_wave_overloads_0_2())
        .def("write", (void (Magick::Image::*)(const std::string&) )&Magick::Image::write)
        .def("write", (void (Magick::Image::*)(Magick::Blob*) )&Magick::Image::write)
        .def("write", (void (Magick::Image::*)(Magick::Blob*, const std::string&) )&Magick::Image::write)
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("write", (void (Magick::Image::*)(Magick::Blob*, const std::string&, const size_t) )&Magick::Image::write)
#else
        .def("write", (void (Magick::Image::*)(Magick::Blob*, const std::string&, const unsigned int) )&Magick::Image::write)
#endif
        .def("zoom", &Magick::Image::zoom)
        .def("adjoin", (void (Magick::Image::*)(const bool) )&Magick::Image::adjoin)
        .def("adjoin", (bool (Magick::Image::*)() const)&Magick::Image::adjoin)
        .def("antiAlias", (void (Magick::Image::*)(const bool) )&Magick::Image::antiAlias)
        .def("antiAlias", (bool (Magick::Image::*)() )&Magick::Image::antiAlias)
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("animationDelay", (void (Magick::Image::*)(const size_t) )&Magick::Image::animationDelay)
        .def("animationDelay", (size_t (Magick::Image::*)() const)&Magick::Image::animationDelay)
        .def("animationIterations", (void (Magick::Image::*)(const size_t) )&Magick::Image::animationIterations)
        .def("animationIterations", (size_t (Magick::Image::*)() const)&Magick::Image::animationIterations)
#else
        .def("animationDelay", (void (Magick::Image::*)(const unsigned int) )&Magick::Image::animationDelay)
        .def("animationDelay", (unsigned int (Magick::Image::*)() const)&Magick::Image::animationDelay)
        .def("animationIterations", (void (Magick::Image::*)(const unsigned int) )&Magick::Image::animationIterations)
        .def("animationIterations", (unsigned int (Magick::Image::*)() const)&Magick::Image::animationIterations)
#endif
        .def("attribute", (void (Magick::Image::*)(const std::string, const std::string) )&Magick::Image::attribute)
        .def("attribute", (std::string (Magick::Image::*)(const std::string) )&Magick::Image::attribute)
        .def("backgroundColor", (void (Magick::Image::*)(const Magick::Color&) )&Magick::Image::backgroundColor)
        .def("backgroundColor", (Magick::Color (Magick::Image::*)() const)&Magick::Image::backgroundColor)
        .def("backgroundTexture", (void (Magick::Image::*)(const std::string&) )&Magick::Image::backgroundTexture)
        .def("backgroundTexture", (std::string (Magick::Image::*)() const)&Magick::Image::backgroundTexture)
        .def("baseColumns", &Magick::Image::baseColumns)
        .def("baseFilename", &Magick::Image::baseFilename)
        .def("baseRows", &Magick::Image::baseRows)
        .def("borderColor", (void (Magick::Image::*)(const Magick::Color&) )&Magick::Image::borderColor)
        .def("borderColor", (Magick::Color (Magick::Image::*)() const)&Magick::Image::borderColor)
        .def("boundingBox", &Magick::Image::boundingBox)
        .def("boxColor", (void (Magick::Image::*)(const Magick::Color&) )&Magick::Image::boxColor)
        .def("boxColor", (Magick::Color (Magick::Image::*)() const)&Magick::Image::boxColor)
        .def("cacheThreshold", &Magick::Image::cacheThreshold)
        .def("chromaBluePrimary", (void (Magick::Image::*)(const double, const double) )&Magick::Image::chromaBluePrimary)
        .def("chromaBluePrimary", (void (Magick::Image::*)(double*, double*) const)&Magick::Image::chromaBluePrimary)
        .def("chromaGreenPrimary", (void (Magick::Image::*)(const double, const double) )&Magick::Image::chromaGreenPrimary)
        .def("chromaGreenPrimary", (void (Magick::Image::*)(double*, double*) const)&Magick::Image::chromaGreenPrimary)
        .def("chromaRedPrimary", (void (Magick::Image::*)(const double, const double) )&Magick::Image::chromaRedPrimary)
        .def("chromaRedPrimary", (void (Magick::Image::*)(double*, double*) const)&Magick::Image::chromaRedPrimary)
        .def("chromaWhitePoint", (void (Magick::Image::*)(const double, const double) )&Magick::Image::chromaWhitePoint)
        .def("chromaWhitePoint", (void (Magick::Image::*)(double*, double*) const)&Magick::Image::chromaWhitePoint)
        .def("classType", (void (Magick::Image::*)(const Magick::ClassType) )&Magick::Image::classType)
        .def("classType", (Magick::ClassType (Magick::Image::*)() const)&Magick::Image::classType)
        .def("clipMask", (void (Magick::Image::*)(const Magick::Image&) )&Magick::Image::clipMask)
        .def("clipMask", (Magick::Image (Magick::Image::*)() const)&Magick::Image::clipMask)
        .def("colorFuzz", (void (Magick::Image::*)(const double) )&Magick::Image::colorFuzz)
        .def("colorFuzz", (double (Magick::Image::*)() const)&Magick::Image::colorFuzz)
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("colorMap", (void (Magick::Image::*)(const size_t, const Magick::Color&) )&Magick::Image::colorMap)
        .def("colorMap", (Magick::Color (Magick::Image::*)(const size_t) const)&Magick::Image::colorMap)
        .def("colorMapSize", (void (Magick::Image::*)(const size_t) )&Magick::Image::colorMapSize)
        .def("colorMapSize", (size_t (Magick::Image::*)() )&Magick::Image::colorMapSize)
#else
        .def("colorMap", (void (Magick::Image::*)(const unsigned int, const Magick::Color&) )&Magick::Image::colorMap)
        .def("colorMap", (Magick::Color (Magick::Image::*)(const unsigned int) const)&Magick::Image::colorMap)
        .def("colorMapSize", (void (Magick::Image::*)(const unsigned int) )&Magick::Image::colorMapSize)
        .def("colorMapSize", (unsigned int (Magick::Image::*)() )&Magick::Image::colorMapSize)
#endif
        .def("colorSpace", (void (Magick::Image::*)(const Magick::ColorspaceType))&Magick::Image::colorSpace)
        .def("colorSpace", (Magick::ColorspaceType (Magick::Image::*)() const)&Magick::Image::colorSpace)
        .def("columns", &Magick::Image::columns)
        .def("comment", (std::string (Magick::Image::*)() const)&Magick::Image::comment)
        .def("compose", (void (Magick::Image::*)(const Magick::CompositeOperator))&Magick::Image::compose)
        .def("compose", (Magick::CompositeOperator (Magick::Image::*)() const)&Magick::Image::compose)
        .def("compressType", (void (Magick::Image::*)(const Magick::CompressionType))&Magick::Image::compressType)
        .def("compressType", (Magick::CompressionType (Magick::Image::*)() const)&Magick::Image::compressType)
        .def("debug", (void (Magick::Image::*)(const bool) )&Magick::Image::debug)
        .def("debug", (bool (Magick::Image::*)() const)&Magick::Image::debug)
        .def("defineValue", (void (Magick::Image::*)(const std::string&, const std::string&, const std::string&) )&Magick::Image::defineValue)
        .def("defineValue", (std::string (Magick::Image::*)(const std::string&, const std::string&) const)&Magick::Image::defineValue)
        .def("defineSet", (void (Magick::Image::*)(const std::string&, const std::string&, bool) )&Magick::Image::defineSet)
        .def("defineSet", (bool (Magick::Image::*)(const std::string&, const std::string&) const)&Magick::Image::defineSet)
        .def("density", (void (Magick::Image::*)(const Magick::Geometry&) )&Magick::Image::density)
        .def("density", (Magick::Geometry (Magick::Image::*)() const)&Magick::Image::density)
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("depth", (void (Magick::Image::*)(const size_t) )&Magick::Image::depth)
        .def("depth", (size_t (Magick::Image::*)() const)&Magick::Image::depth)
#else
        .def("depth", (void (Magick::Image::*)(const unsigned int) )&Magick::Image::depth)
        .def("depth", (unsigned int (Magick::Image::*)() const)&Magick::Image::depth)
#endif
        .def("directory", &Magick::Image::directory)
        .def("endian", (void (Magick::Image::*)(const Magick::EndianType))&Magick::Image::endian)
        .def("endian", (Magick::EndianType (Magick::Image::*)() const)&Magick::Image::endian)
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("exifProfile", (void (Magick::Image::*)(const Magick::Blob&))&Magick::Image::exifProfile)
        .def("exifProfile", (Magick::Blob (Magick::Image::*)() const)&Magick::Image::exifProfile)
#endif
        .def("fileName", (void (Magick::Image::*)(const std::string&) )&Magick::Image::fileName)
        .def("fileName", (std::string (Magick::Image::*)() const)&Magick::Image::fileName)
        .def("fileSize", &Magick::Image::fileSize)
        .def("fillColor", (void (Magick::Image::*)(const Magick::Color&) )&Magick::Image::fillColor)
        .def("fillColor", (Magick::Color (Magick::Image::*)() const)&Magick::Image::fillColor)
        .def("fillRule", (void (Magick::Image::*)(const Magick::FillRule&))&Magick::Image::fillRule)
        .def("fillRule", (Magick::FillRule (Magick::Image::*)(void) const)&Magick::Image::fillRule)
        .def("fillPattern", (void (Magick::Image::*)(const Magick::Image&) )&Magick::Image::fillPattern)
        .def("fillPattern", (Magick::Image (Magick::Image::*)() const)&Magick::Image::fillPattern)
        .def("filterType", (void (Magick::Image::*)(const Magick::FilterTypes) )&Magick::Image::filterType)
        .def("font", (void (Magick::Image::*)(const std::string&) )&Magick::Image::font)
        .def("font", (std::string (Magick::Image::*)() const)&Magick::Image::font)
        .def("fontPointsize", (void (Magick::Image::*)(const double) )&Magick::Image::fontPointsize)
        .def("fontPointsize", (double (Magick::Image::*)() const)&Magick::Image::fontPointsize)
        .def("fontTypeMetrics", &Magick::Image::fontTypeMetrics)
        .def("format", &Magick::Image::format)
        .def("gamma", (double (Magick::Image::*)() const)&Magick::Image::gamma)
        .def("geometry", &Magick::Image::geometry)
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("gifDisposeMethod", (void (Magick::Image::*)(const size_t) )&Magick::Image::gifDisposeMethod)
        .def("gifDisposeMethod", (size_t (Magick::Image::*)() const)&Magick::Image::gifDisposeMethod)
#else
        .def("gifDisposeMethod", (void (Magick::Image::*)(const unsigned int) )&Magick::Image::gifDisposeMethod)
        .def("gifDisposeMethod", (unsigned int (Magick::Image::*)() const)&Magick::Image::gifDisposeMethod)
#endif
        .def("iccColorProfile", (void (Magick::Image::*)(const Magick::Blob&) )&Magick::Image::iccColorProfile)
        .def("iccColorProfile", (Magick::Blob (Magick::Image::*)() const)&Magick::Image::iccColorProfile)
        .def("interlaceType", (void (Magick::Image::*)(const Magick::InterlaceType))&Magick::Image::interlaceType)
        .def("interlaceType", (Magick::InterlaceType (Magick::Image::*)() const)&Magick::Image::interlaceType)
        .def("iptcProfile", (void (Magick::Image::*)(const Magick::Blob&) )&Magick::Image::iptcProfile)
        .def("iptcProfile", (Magick::Blob (Magick::Image::*)() const)&Magick::Image::iptcProfile)
        .def("isValid", (void (Magick::Image::*)(const bool) )&Magick::Image::isValid)
        .def("isValid", (bool (Magick::Image::*)() const)&Magick::Image::isValid)
        .def("label", (std::string (Magick::Image::*)() const)&Magick::Image::label)
        .def("lineWidth", (void (Magick::Image::*)(const double) )&Magick::Image::lineWidth)
        .def("lineWidth", (double (Magick::Image::*)() const)&Magick::Image::lineWidth)
        .def("magick", (void (Magick::Image::*)(const std::string&) )&Magick::Image::magick)
        .def("magick", (std::string (Magick::Image::*)() const)&Magick::Image::magick)
        .def("matte", (void (Magick::Image::*)(const bool) )&Magick::Image::matte)
        .def("matte", (bool (Magick::Image::*)() const)&Magick::Image::matte)
        .def("matteColor", (void (Magick::Image::*)(const Magick::Color&) )&Magick::Image::matteColor)
        .def("matteColor", (Magick::Color (Magick::Image::*)() const)&Magick::Image::matteColor)
        .def("meanErrorPerPixel", &Magick::Image::meanErrorPerPixel)
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("modulusDepth", (void (Magick::Image::*)(const size_t) )&Magick::Image::modulusDepth)
        .def("modulusDepth", (size_t (Magick::Image::*)() const)&Magick::Image::modulusDepth)
#else
        .def("modulusDepth", (void (Magick::Image::*)(const unsigned int) )&Magick::Image::modulusDepth)
        .def("modulusDepth", (unsigned int (Magick::Image::*)() const)&Magick::Image::modulusDepth)
#endif
        .def("montageGeometry", &Magick::Image::montageGeometry)
        .def("monochrome", (void (Magick::Image::*)(const bool) )&Magick::Image::monochrome)
        .def("monochrome", (bool (Magick::Image::*)() const)&Magick::Image::monochrome)
        .def("normalizedMaxError", &Magick::Image::normalizedMaxError)
        .def("normalizedMeanError", &Magick::Image::normalizedMeanError)
#ifdef PGMAGICK_LIB_GRAPHICSMAGICK_1_3_x
        .def("orientation", (void (Magick::Image::*)(const Magick::OrientationType))&Magick::Image::orientation)
        .def("orientation", (Magick::OrientationType (Magick::Image::*)() const)&Magick::Image::orientation)
#endif
        .def("page", (void (Magick::Image::*)(const Magick::Geometry&) )&Magick::Image::page)
        .def("page", (Magick::Geometry (Magick::Image::*)() const)&Magick::Image::page)
        .def("penColor", (void (Magick::Image::*)(const Magick::Color&) )&Magick::Image::penColor)
        .def("penColor", (Magick::Color (Magick::Image::*)() const)&Magick::Image::penColor)
        .def("penTexture", (void (Magick::Image::*)(const Magick::Image&) )&Magick::Image::penTexture)
        .def("penTexture", (Magick::Image (Magick::Image::*)() const)&Magick::Image::penTexture)
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("pixelColor", (void (Magick::Image::*)(const ::ssize_t, const ::ssize_t, const Magick::Color&))&Magick::Image::pixelColor)
        .def("pixelColor", (Magick::Color (Magick::Image::*)(const ::ssize_t, const ::ssize_t) const)&Magick::Image::pixelColor)
#else
        .def("pixelColor", (void (Magick::Image::*)(const unsigned int, const unsigned int, const Magick::Color&))&Magick::Image::pixelColor)
        .def("pixelColor", (Magick::Color (Magick::Image::*)(const unsigned int, const unsigned int) const)&Magick::Image::pixelColor)
#endif
        .def("profile", (void (Magick::Image::*)(const std::string, const Magick::Blob&))&Magick::Image::profile)
        .def("profile", (Magick::Blob (Magick::Image::*)(const std::string) const)&Magick::Image::profile)
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("quality", (void (Magick::Image::*)(const size_t) )&Magick::Image::quality)
        .def("quality", (size_t (Magick::Image::*)() const)&Magick::Image::quality)
        .def("quantizeColors", (void (Magick::Image::*)(const size_t) )&Magick::Image::quantizeColors)
        .def("quantizeColors", (size_t (Magick::Image::*)() const)&Magick::Image::quantizeColors)
#else
        .def("quality", (void (Magick::Image::*)(const unsigned int) )&Magick::Image::quality)
        .def("quality", (unsigned int (Magick::Image::*)() const)&Magick::Image::quality)
        .def("quantizeColors", (void (Magick::Image::*)(const unsigned int) )&Magick::Image::quantizeColors)
        .def("quantizeColors", (unsigned int (Magick::Image::*)() const)&Magick::Image::quantizeColors)
#endif
        .def("quantizeColorSpace", (void (Magick::Image::*)(const Magick::ColorspaceType) )&Magick::Image::quantizeColorSpace)
        .def("quantizeColorSpace", (Magick::ColorspaceType (Magick::Image::*)() const)&Magick::Image::quantizeColorSpace)
        .def("quantizeDither", (void (Magick::Image::*)(const bool) )&Magick::Image::quantizeDither)
        .def("quantizeDither", (bool (Magick::Image::*)() const)&Magick::Image::quantizeDither)
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("quantizeTreeDepth", (void (Magick::Image::*)(const size_t) )&Magick::Image::quantizeTreeDepth)
        .def("quantizeTreeDepth", (size_t (Magick::Image::*)() const)&Magick::Image::quantizeTreeDepth)
#else
        .def("quantizeTreeDepth", (void (Magick::Image::*)(const unsigned int) )&Magick::Image::quantizeTreeDepth)
        .def("quantizeTreeDepth", (unsigned int (Magick::Image::*)() const)&Magick::Image::quantizeTreeDepth)
#endif
        .def("renderingIntent", (void (Magick::Image::*)(const Magick::RenderingIntent) )&Magick::Image::renderingIntent)
        .def("renderingIntent", (Magick::RenderingIntent (Magick::Image::*)() const)&Magick::Image::renderingIntent)
        .def("resolutionUnits", (void (Magick::Image::*)(const Magick::ResolutionType) )&Magick::Image::resolutionUnits)
        .def("resolutionUnits", (Magick::ResolutionType (Magick::Image::*)() const)&Magick::Image::resolutionUnits)
        .def("rows", &Magick::Image::rows)
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("scene", (void (Magick::Image::*)(const size_t) )&Magick::Image::scene)
        .def("scene", (size_t (Magick::Image::*)() const)&Magick::Image::scene)
#else
        .def("scene", (void (Magick::Image::*)(const unsigned int) )&Magick::Image::scene)
        .def("scene", (unsigned int (Magick::Image::*)() const)&Magick::Image::scene)
#endif
        .def("signature", &Magick::Image::signature, Magick_Image_signature_overloads_0_1())
        .def("size", (void (Magick::Image::*)(const Magick::Geometry&) )&Magick::Image::size)
        .def("size", (Magick::Geometry (Magick::Image::*)() const)&Magick::Image::size)
        .def("statistics", &Magick::Image::statistics)
        .def("strokeAntiAlias", (void (Magick::Image::*)(const bool) )&Magick::Image::strokeAntiAlias)
        .def("strokeAntiAlias", (bool (Magick::Image::*)() const)&Magick::Image::strokeAntiAlias)
        .def("strokeColor", (void (Magick::Image::*)(const Magick::Color&) )&Magick::Image::strokeColor)
        .def("strokeColor", (Magick::Color (Magick::Image::*)() const)&Magick::Image::strokeColor)
        .def("strokeDashArray", (void (Magick::Image::*)(const double*) )&Magick::Image::strokeDashArray)
#if 0
        .def("strokeDashArray", (const double* (Magick::Image::*)() const)&Magick::Image::strokeDashArray)
#endif
        .def("strokeDashOffset", (void (Magick::Image::*)(const double) )&Magick::Image::strokeDashOffset)
        .def("strokeDashOffset", (double (Magick::Image::*)() const)&Magick::Image::strokeDashOffset)
        .def("strokeLineCap", (void (Magick::Image::*)(const Magick::LineCap) )&Magick::Image::strokeLineCap)
        .def("strokeLineCap", (Magick::LineCap (Magick::Image::*)() const)&Magick::Image::strokeLineCap)
        .def("strokeLineJoin", (void (Magick::Image::*)(const Magick::LineJoin) )&Magick::Image::strokeLineJoin)
        .def("strokeLineJoin", (Magick::LineJoin (Magick::Image::*)() const)&Magick::Image::strokeLineJoin)
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("strokeMiterLimit", (void (Magick::Image::*)(const size_t) )&Magick::Image::strokeMiterLimit)
        .def("strokeMiterLimit", (size_t (Magick::Image::*)() const)&Magick::Image::strokeMiterLimit)
#else
        .def("strokeMiterLimit", (void (Magick::Image::*)(const unsigned int) )&Magick::Image::strokeMiterLimit)
        .def("strokeMiterLimit", (unsigned int (Magick::Image::*)() const)&Magick::Image::strokeMiterLimit)
#endif
        .def("strokePattern", (void (Magick::Image::*)(const Magick::Image&) )&Magick::Image::strokePattern)
        .def("strokePattern", (Magick::Image (Magick::Image::*)() const)&Magick::Image::strokePattern)
        .def("strokeWidth", (void (Magick::Image::*)(const double) )&Magick::Image::strokeWidth)
        .def("strokeWidth", (double (Magick::Image::*)() const)&Magick::Image::strokeWidth)
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("subImage", (void (Magick::Image::*)(const size_t) )&Magick::Image::subImage)
        .def("subImage", (size_t (Magick::Image::*)() const)&Magick::Image::subImage)
        .def("subRange", (void (Magick::Image::*)(const size_t) )&Magick::Image::subRange)
        .def("subRange", (size_t (Magick::Image::*)() const)&Magick::Image::subRange)
#else
        .def("subImage", (void (Magick::Image::*)(const unsigned int) )&Magick::Image::subImage)
        .def("subImage", (unsigned int (Magick::Image::*)() const)&Magick::Image::subImage)
        .def("subRange", (void (Magick::Image::*)(const unsigned int) )&Magick::Image::subRange)
        .def("subRange", (unsigned int (Magick::Image::*)() const)&Magick::Image::subRange)
#endif
        .def("textEncoding", (void (Magick::Image::*)(const std::string&) )&Magick::Image::textEncoding)
        .def("textEncoding", (std::string (Magick::Image::*)() const)&Magick::Image::textEncoding)
        .def("tileName", (void (Magick::Image::*)(const std::string&) )&Magick::Image::tileName)
        .def("tileName", (std::string (Magick::Image::*)() const)&Magick::Image::tileName)
        .def("totalColors", &Magick::Image::totalColors)
        .def("transformOrigin", &Magick::Image::transformOrigin)
        .def("transformRotation", &Magick::Image::transformRotation)
        .def("transformReset", &Magick::Image::transformReset)
        .def("transformScale", &Magick::Image::transformScale)
        .def("transformSkewX", &Magick::Image::transformSkewX)
        .def("transformSkewY", &Magick::Image::transformSkewY)
        .def("type", (Magick::ImageType (Magick::Image::*)() const)&Magick::Image::type)
        .def("verbose", (void (Magick::Image::*)(const bool) )&Magick::Image::verbose)
        .def("verbose", (bool (Magick::Image::*)() const)&Magick::Image::verbose)
        .def("view", (void (Magick::Image::*)(const std::string&) )&Magick::Image::view)
        .def("view", (std::string (Magick::Image::*)() const)&Magick::Image::view)
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("virtualPixelMethod", (void (Magick::Image::*)(const Magick::VirtualPixelMethod))&Magick::Image::virtualPixelMethod)
        .def("virtualPixelMethod", (Magick::VirtualPixelMethod (Magick::Image::*)() const)&Magick::Image::virtualPixelMethod)
#endif
        .def("x11Display", (void (Magick::Image::*)(const std::string&) )&Magick::Image::x11Display)
        .def("x11Display", (std::string (Magick::Image::*)() const)&Magick::Image::x11Display)
        .def("xResolution", &Magick::Image::xResolution)
        .def("yResolution", &Magick::Image::yResolution)
#if 0
        .def("getConstPixels",)
        .def("getIndexes",)
        .def("getConstIndexes",)
        .def("getPixels",)
        .def("setPixels",)
#endif
        .def("syncPixels", &Magick::Image::syncPixels)
        .def("readPixels", &Magick::Image::readPixels)
        .def("writePixels", &Magick::Image::writePixels)
        /* no user-serviceable parts */
        .def("modifyImage", &Magick::Image::modifyImage)
        .def("throwImageException", &Magick::Image::throwImageException)
        .def("registerId", &Magick::Image::registerId)
        .def("unregisterId", &Magick::Image::unregisterId)
        .staticmethod("cacheThreshold")
        .def( self == self )
        .def( self != self )
        .def( self > self )
        .def( self < self )
        .def( self >= self )
        .def( self <= self )
    ;
}
