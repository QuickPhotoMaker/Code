#include "images.h"
void Images::add(const Image& image)
{
	images.push_back(image);
}
void Images::remove(const int& index)
{
	images.erase(images.begin() + index);
}
int Images::size() const 
{
	return images.size();
}
void Images::clear()
{
	images.clear();
}
const Image& Images::operator[](const int& index) const 
{
	return images[index];
}