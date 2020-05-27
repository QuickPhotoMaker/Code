#pragma once
#include "images.h"
#include <fstream>
class DAOImage
{
public:
	//saves the image path
	void save(const Image& image);

	//loads the image path
	void load(Images& images);
};