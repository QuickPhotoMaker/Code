#pragma once
#include <vector>
#include "image.h"
class Images
{
private:
	std::vector<Image> images;
public:
	void add(const Image& image);
	void remove(const int& index);
	int size() const;
	void clear();
	const Image& operator[](const int& index) const;
};