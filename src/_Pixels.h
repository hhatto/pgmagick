#ifndef _PIXELS_HEADER_
#define _PIXELS_HEADER_

#include <Magick++/Pixels.h>
#include "_ArrayProxy.h"

// Holds reference to C++ PixelPacket alowing it to be changed via this proxy from python
class PixelPacketProxy {
public:
    Magick::PixelPacket& packet;

    explicit PixelPacketProxy(Magick::PixelPacket& packet) : packet(packet) {}

    Magick::Quantum get_red() const { return packet.red; }
    Magick::Quantum get_green() const { return packet.green; }
    Magick::Quantum get_blue() const { return packet.blue; }
    Magick::Quantum get_opacity() const { return packet.opacity; }

    void set_red(Magick::Quantum value) { packet.red = value; }
    void set_green(Magick::Quantum value) { packet.green = value; }
    void set_blue(Magick::Quantum value) { packet.blue = value; }
    void set_opacity(Magick::Quantum value) { packet.opacity = value; }
};

typedef ArrayProxy<Magick::PixelPacket, PixelPacketProxy, Magick::Image> PixelPacketArrayProxy;
typedef ArrayProxy<const Magick::PixelPacket, Magick::PixelPacket, Magick::Image> PixelPacketConstArrayProxy;

#endif //_PIXELS_HEADER_
