#include <boost/python.hpp>

#include <Magick++.h>
#include <Magick++/STL.h>

using namespace boost::python;


class _ImageList {
public:
    _ImageList(void);
    _ImageList(const std::string &imageSpec);

    int _length(void);

    void _append(Magick::Image _image);

    void _appendImages(Magick::Image *_image);

    void _coalesceImages(void);

    void _readImages(const std::string &imageSpec);

    void _writeImages(const std::string &imageSpec);

    void _animationDelayImage(const unsigned int delay);

    void _scaleImage(const Magick::Geometry &geometry);

private:
    std::list<Magick::Image> _images;
};

/* _ImageList class implementation */
_ImageList::_ImageList(void)
{
}
_ImageList::_ImageList(const std::string &imageSpec)
{
    Magick::readImages(&_images, imageSpec);
}
int _ImageList::_length(void)
{
    return _images.size();
}

void _ImageList::_append(Magick::Image _image)
{
    _images.push_back(_image);
}

void _ImageList::_appendImages(Magick::Image *_image)
{
    Magick::appendImages(_image, _images.begin(), _images.end());
}

void _ImageList::_coalesceImages(void)
{
    Magick::coalesceImages(&_images, _images.begin(), _images.end());
}

void _ImageList::_readImages(const std::string &imageSpec)
{
    Magick::readImages(&_images, imageSpec);
}

void _ImageList::_writeImages(const std::string &imageSpec)
{
    Magick::writeImages(_images.begin(), _images.end(), imageSpec);
}

void _ImageList::_animationDelayImage(const unsigned int delay)
{
    for_each(_images.begin(), _images.end(), Magick::animationDelayImage(delay));
}

void _ImageList::_scaleImage(const Magick::Geometry &geometry)
{
    for_each(_images.begin(), _images.end(), Magick::scaleImage(geometry));
}


void __STL()
{
    class_< _ImageList >("ImageList", init< >())
        .def("__len__", &_ImageList::_length)
        .def("append", (void (_ImageList::*)(Magick::Image))&_ImageList::_append)
        .def("appendImages", (void (_ImageList::*)(Magick::Image*))&_ImageList::_appendImages)
        .def("coalesceImags", (void (_ImageList::*)(void))&_ImageList::_coalesceImages)
        .def("readImages", (void (_ImageList::*)(const std::string&))&_ImageList::_readImages)
        .def("writeImages", (void (_ImageList::*)(const std::string&))&_ImageList::_writeImages)

        .def("animationDelayImages", (void (_ImageList::*)(const unsigned int))&_ImageList::_animationDelayImage)
        .def("scaleImages", (void (_ImageList::*)(const Magick::Geometry&))&_ImageList::_scaleImage)
    ;
}
