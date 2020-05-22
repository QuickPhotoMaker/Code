#include "image.h"
Image::Image(const std::string& _path)
	:path(_path)
{}
Image::Image(const Image& image) 
{
	copy(image);
}
const Image& Image::operator=(const Image& image) 
{
	copy(image);
	return *this;
}
void Image::copy(const Image& image) 
{
	path = image.path;
}
void Image::setPath(const std::string& value) 
{
	path = value;
}
std::string Image::getPath() const 
{
	return path;
}
std::ostream& operator<<(std::ostream& stream, const Image& image)
{
	stream << image.getPath();
	return stream;
}