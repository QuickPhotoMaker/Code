#include "image.h"
//Constructor
Image::Image(const std::string& _path)
	:path(_path)
{}

/*
 * sets the path of the image
 * @param path: path of the image
 */
void Image::setPath(const std::string& _path)
{
	path = _path;
}

//returns the path of the image
std::string Image::getPath() const
{
	return path;
}