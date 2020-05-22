#pragma once
#include "image.h"
#include <vector>

class Images
{
	//Collection of images
	std::vector<Image> images;
public:

	/**
	 * Adds an image to the collection
	 * @param image: Image to add
	 */
	void add(const Image& complaint);

	/**
	 * Removes an image from the collection
	 * @param index: index of the image to remove
	 */
	void remove(const int& index);

	/**
	 * Returns the size of the collection
	 */
	int size() const;

	/**
	 * Clears the collection
	 */
	void clear();

	/**
	 * Returns an image from the collection
	 * @param index: Index of the image to return
	 */
	const Image& operator[](const int& index) const;
};

