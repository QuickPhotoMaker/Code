#include "images.h"
/**
	 * Adds an image to the collection
	 * @param image: Image to add
	 */
void Images::add(const Image& complaint)
{
    images.push_back(complaint);
}

/**
 * Removes an image from the collection
 * @param index: index of the image to remove
 */
void Images::remove(const int& index) 
{
    images.erase(images.begin() + index);
}

/**
 * Returns the size of the collection
 */
int Images::size() const 
{
    return images.size();
}

/**
 * Clears the collection
 */
void Images::clear() 
{
    images.clear();
}

/**
 * Returns an image from the collection
 * @param index: Index of the image to return
 */
const Image& Images::operator[](const int& index) const 
{
    return images[index];
}