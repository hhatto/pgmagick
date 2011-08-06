#include <boost/python.hpp>

#include <Magick++/Montage.h>

using namespace boost::python;


void __Montage()
{
    class_< Magick::Montage >("Montage", init<  >())
        .def("backgroundColor",
             (void (Magick::Montage::*)(const Magick::Color&))
             &Magick::Montage::backgroundColor)
        .def("backgroundColor", (Magick::Color (Magick::Montage::*)() const)
             &Magick::Montage::backgroundColor)
        .def("compose",
             (void (Magick::Montage::*)(const Magick::CompositeOperator))
             &Magick::Montage::compose)
        .def("compose",
             (Magick::CompositeOperator (Magick::Montage::*)() const)
             &Magick::Montage::compose)
        .def("fileName", (void (Magick::Montage::*)(const std::string&))
             &Magick::Montage::fileName)
        .def("fileName", (std::string (Magick::Montage::*)() const)
             &Magick::Montage::fileName)
        .def("fillColor", (void (Magick::Montage::*)(const Magick::Color&))
             &Magick::Montage::fillColor)
        .def("fillColor", (Magick::Color (Magick::Montage::*)() const)
             &Magick::Montage::fillColor)
        .def("geometry", (void (Magick::Montage::*)(const Magick::Geometry&))
             &Magick::Montage::geometry)
        .def("geometry", (Magick::Geometry (Magick::Montage::*)() const)
             &Magick::Montage::geometry)
        .def("gravity", (void (Magick::Montage::*)(const Magick::GravityType))
             &Magick::Montage::gravity)
        .def("gravity", (Magick::GravityType (Magick::Montage::*)() const)
             &Magick::Montage::gravity)
        .def("label", (void (Magick::Montage::*)(const std::string&))
             &Magick::Montage::label)
        .def("label", (std::string (Magick::Montage::*)() const)
             &Magick::Montage::label)
        .def("penColor", (void (Magick::Montage::*)(const Magick::Color&))
             &Magick::Montage::penColor)
        .def("penColor", (Magick::Color (Magick::Montage::*)() const)
             &Magick::Montage::penColor)
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("pointSize", (void (Magick::Montage::*)(size_t))
             &Magick::Montage::pointSize)
        .def("pointSize", (size_t (Magick::Montage::*)() const)
             &Magick::Montage::pointSize)
#else
        .def("pointSize", (void (Magick::Montage::*)(unsigned int))
             &Magick::Montage::pointSize)
        .def("pointSize", (unsigned int (Magick::Montage::*)() const)
             &Magick::Montage::pointSize)
#endif
        .def("shadow", (void (Magick::Montage::*)(const bool))
             &Magick::Montage::shadow)
        .def("shadow", (bool (Magick::Montage::*)() const)
             &Magick::Montage::shadow)
        .def("strokeColor", (void (Magick::Montage::*)(const Magick::Color&))
             &Magick::Montage::strokeColor)
        .def("strokeColor", (Magick::Color (Magick::Montage::*)() const)
             &Magick::Montage::strokeColor)
        .def("texture", (void (Magick::Montage::*)(const std::string&))
             &Magick::Montage::texture)
        .def("texture", (std::string (Magick::Montage::*)() const)
             &Magick::Montage::texture)
        .def("title", (void (Magick::Montage::*)(const std::string&))
             &Magick::Montage::title)
        .def("title", (std::string (Magick::Montage::*)() const)
             &Magick::Montage::title)
        .def("transparentColor",
             (void (Magick::Montage::*)(const Magick::Color&))
             &Magick::Montage::transparentColor)
        .def("transparentColor", (Magick::Color (Magick::Montage::*)() const)
             &Magick::Montage::transparentColor)
    ;

    class_< Magick::MontageFramed >("MontageFramed", init<  >())
        .def("borderColor",
             (void (Magick::MontageFramed::*)(const Magick::Color&))
             &Magick::MontageFramed::borderColor)
        .def("borderColor", (Magick::Color (Magick::MontageFramed::*)() const)
             &Magick::MontageFramed::borderColor)
#ifdef PGMAGICK_LIB_IMAGEMAGICK
        .def("borderWidth", (void (Magick::MontageFramed::*)(size_t))
             &Magick::MontageFramed::borderWidth)
        .def("borderWidth", (size_t (Magick::MontageFramed::*)() const)
             &Magick::MontageFramed::borderWidth)
#else
        .def("borderWidth", (void (Magick::MontageFramed::*)(unsigned int))
             &Magick::MontageFramed::borderWidth)
        .def("borderWidth", (unsigned int (Magick::MontageFramed::*)() const)
             &Magick::MontageFramed::borderWidth)
#endif
        .def("frameGeometry",
             (void (Magick::MontageFramed::*)(const Magick::Geometry&))
             &Magick::MontageFramed::geometry)
        .def("frameGeometry",
             (Magick::Geometry (Magick::MontageFramed::*)() const)
             &Magick::MontageFramed::geometry)
        .def("matteColor",
             (void (Magick::MontageFramed::*)(const Magick::Color&))
             &Magick::MontageFramed::matteColor)
        .def("matteColor", (Magick::Color (Magick::MontageFramed::*)() const)
             &Magick::MontageFramed::matteColor)
    ;
}
