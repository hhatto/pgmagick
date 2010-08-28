#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Include.h>

using namespace boost::python;


void __CompressionType()
{
    enum_< Magick::CompressionType >("CompressionType")
        .value("UndefinedCompression", Magick::UndefinedCompression)
        .value("NoCompression", Magick::NoCompression)
        .value("BZipCompression", Magick::BZipCompression)
        .value("FaxCompression", Magick::FaxCompression)
        .value("Group4Compression", Magick::Group4Compression)
        .value("JPEGCompression", Magick::JPEGCompression)
        .value("LZWCompression", Magick::LZWCompression)
        .value("RLECompression", Magick::RLECompression)
        .value("ZipCompression", Magick::ZipCompression)
    ;
}
