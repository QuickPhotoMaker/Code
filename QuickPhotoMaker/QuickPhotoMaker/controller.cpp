#include "controller.h"
#include <fstream>
Controller::Controller()
	:Subject(), currentScreen(0)
{
	daoImage.load(images);
}
void Controller::setScreen(int idView) 
{
	if (idView >= 0 && idView <= 10)
	{
		currentScreen = idView;
		notify();
	}
}
int Controller::getCurrentScreen() 
{
	return currentScreen;
}
/**
 * Returns the collection of images
 */
const Images& Controller::getImages()
{
	return images;
}

/**
 * Add an image to the collection
 * @param image: Image to add
 */
void Controller::addImage(const Image& image)
{
	images.add(image);

	daoImage.save(image);

	setScreen(0);
}

/**
 * Removes an image from the collection
 * @param index: Index of the image to remove
 */
void Controller::removeImage(const int& index)
{
	images.remove(index);
	notify();
}