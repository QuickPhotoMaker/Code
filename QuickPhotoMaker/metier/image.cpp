#include "image.h"
Image::Image(const std::string& _path)
	:path(_path)
{}
void Image::setPath(const std::string& _path)
{
	path = _path;
}
std::string Image::getPath() const
{
	return path;
}