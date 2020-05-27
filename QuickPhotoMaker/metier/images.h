#pragma once
#include <vector>
#include "image.h"
class Images
{
private:
	//collection of images
	std::vector<Image> images;
public:
	/*
	 * adds an image to the collection
	 * @param image: Image
	 */
	void add(const Image& image);

	/*
	 * removes an image from the collection
	 * @param index: index of the image to remove
	 */
	void remove(const int& index);

	//returns the size of the collection
	int size() const;

	//clears the collection
	void clear();

	/*
	 * returns an image from the collection
	 * @param index: index of the image
	 */
	const Image& operator[](const int& index) const;
};