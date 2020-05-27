#include "images.h"
/*
 * adds an image to the collection
 * @param image: Image
 */
void Images::add(const Image& image)
{
	images.push_back(image);
}

/*
 * removes an image from the collection
 * @param index: index of the image to remove
 */
void Images::remove(const int& index)
{
	images.erase(images.begin() + index);
}

//returns the size of the collection
int Images::size() const 
{
	return images.size();
}

//clears the collection
void Images::clear()
{
	images.clear();
}

/*
 * returns an image from the collection
 * @param index: index of the image
 */
const Image& Images::operator[](const int& index) const 
{
	return images[index];
}