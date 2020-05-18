#pragma once
#include "subject.h"
#include "images.h"
#include "daoImage.h"
class Controller: public Subject
{
private:
	int currentScreen;
	Images images;
	DAOImage daoImage;
public:
	Controller();
	void setScreen(int idView);
	int getCurrentScreen();
	const Images& getImages();
	void addImage(const Image& image);
	void removeImage(const int& index);
	void saveImage(const Image& image) const;
};