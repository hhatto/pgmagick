#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <Magick++/Color.h>

using namespace boost::python;


void __Color()
{
    class_< Magick::Color >("Color", init<  >())
        .def(init< Magick::Quantum, Magick::Quantum, Magick::Quantum >())
        .def(init< Magick::Quantum, Magick::Quantum, Magick::Quantum, Magick::Quantum >())
        .def(init< const std::string& >())
        .def(init< const char* >())
        .def(init< const Magick::Color& >())
        .def(init< const Magick::PixelPacket& >())
        .def("redQuantum", (void (Magick::Color::*)(Magick::Quantum) )&Magick::Color::redQuantum)
        .def("redQuantum", (Magick::Quantum (Magick::Color::*)() const)&Magick::Color::redQuantum)
        .def("greenQuantum", (void (Magick::Color::*)(Magick::Quantum) )&Magick::Color::greenQuantum)
        .def("greenQuantum", (Magick::Quantum (Magick::Color::*)() const)&Magick::Color::greenQuantum)
        .def("blueQuantum", (void (Magick::Color::*)(Magick::Quantum) )&Magick::Color::blueQuantum)
        .def("blueQuantum", (Magick::Quantum (Magick::Color::*)() const)&Magick::Color::blueQuantum)
        .def("alphaQuantum", (void (Magick::Color::*)(Magick::Quantum) )&Magick::Color::alphaQuantum)
        .def("alphaQuantum", (Magick::Quantum (Magick::Color::*)() const)&Magick::Color::alphaQuantum)
        .def("alpha", (void (Magick::Color::*)(double) )&Magick::Color::alpha)
        .def("alpha", (double (Magick::Color::*)() const)&Magick::Color::alpha)
        .def("isValid", (void (Magick::Color::*)(bool) )&Magick::Color::isValid)
        .def("isValid", (bool (Magick::Color::*)() const)&Magick::Color::isValid)
        .def("intensity", &Magick::Color::intensity)
        .def("scaleDoubleToQuantum", &Magick::Color::scaleDoubleToQuantum)
        .def("scaleQuantumToDouble", (double (*)(const Magick::Quantum))&Magick::Color::scaleQuantumToDouble)
        .def("scaleQuantumToDouble", (double (*)(const double))&Magick::Color::scaleQuantumToDouble)
        .staticmethod("scaleDoubleToQuantum")
        .staticmethod("scaleQuantumToDouble")
        .def( self > self )
        .def( self < self )
        .def( self == self )
        .def( self != self )
        .def( self <= self )
        .def( self >= self )
        .def("to_std_string", &Magick::Color::operator std::string)
        .def("to_Magick_PixelPacket", &Magick::Color::operator Magick::PixelPacket)
    ;

    class_< Magick::ColorHSL >("ColorHSL", init<  >())
        .def(init< double, double, double >())
        .def(init< const Magick::Color& >())
        .def("hue", (double (Magick::ColorHSL::*)() const)&Magick::ColorHSL::hue)
        .def("hue", (void (Magick::ColorHSL::*)(double) )&Magick::ColorHSL::hue)
        .def("saturation", (double (Magick::ColorHSL::*)() const)&Magick::ColorHSL::saturation)
        .def("saturation", (void (Magick::ColorHSL::*)(double) )&Magick::ColorHSL::saturation)
        .def("luminosity", (double (Magick::ColorHSL::*)() const)&Magick::ColorHSL::luminosity)
        .def("luminosity", (void (Magick::ColorHSL::*)(double) )&Magick::ColorHSL::luminosity)
    ;

    class_< Magick::ColorGray >("ColorGray", init<  >())
        .def(init< double >())
        .def(init< const Magick::Color& >())
        .def("shade", (double (Magick::ColorGray::*)() const)&Magick::ColorGray::shade)
        .def("shade", (void (Magick::ColorGray::*)(double) )&Magick::ColorGray::shade)
    ;

    class_< Magick::ColorMono >("ColorMono", init<  >())
        .def(init< bool >())
        .def(init< const Magick::Color& >())
        .def("mono", (void (Magick::ColorMono::*)(bool) )&Magick::ColorMono::mono)
        .def("mono", (bool (Magick::ColorMono::*)() const)&Magick::ColorMono::mono)
    ;

    class_< Magick::ColorRGB >("ColorRGB", init<  >())
        .def(init< double, double, double >())
        .def(init< const Magick::Color& >())
        .def("red", (void (Magick::ColorRGB::*)(double) )&Magick::ColorRGB::red)
        .def("red", (double (Magick::ColorRGB::*)() const)&Magick::ColorRGB::red)
        .def("green", (void (Magick::ColorRGB::*)(double) )&Magick::ColorRGB::green)
        .def("green", (double (Magick::ColorRGB::*)() const)&Magick::ColorRGB::green)
        .def("blue", (void (Magick::ColorRGB::*)(double) )&Magick::ColorRGB::blue)
        .def("blue", (double (Magick::ColorRGB::*)() const)&Magick::ColorRGB::blue)
    ;

    class_< Magick::ColorYUV >("ColorYUV", init<  >())
        .def(init< double, double, double >())
        .def(init< const Magick::Color& >())
        .def("u", (void (Magick::ColorYUV::*)(double) )&Magick::ColorYUV::u)
        .def("u", (double (Magick::ColorYUV::*)() const)&Magick::ColorYUV::u)
        .def("v", (void (Magick::ColorYUV::*)(double) )&Magick::ColorYUV::v)
        .def("v", (double (Magick::ColorYUV::*)() const)&Magick::ColorYUV::v)
        .def("y", (void (Magick::ColorYUV::*)(double) )&Magick::ColorYUV::y)
        .def("y", (double (Magick::ColorYUV::*)() const)&Magick::ColorYUV::y)
    ;

    implicitly_convertible<std::string,Magick::Color>();
}

