#pragma once
#include "images.h"
#include <fstream>
class DAOImage
{
public:
	void save(const Image& image);
	void load(Images& images);
};