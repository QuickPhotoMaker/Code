#include "controller.h"
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
 * Returns the collection of complaints
 */
const Images& Controller::getImages()
{
	return images;
}

/**
 * Add a  complaint to the collection
 * @param complaint: Complaint to add
 */
void Controller::addImage(const Image& image)
{
	images.add(image);

	daoImage.save(image);

	setScreen(0);
}

/**
 * Removes a complaint from the collection
 * @param index: Index of the complaint to remove
 */
void Controller::removeImage(const int& index)
{
	images.remove(index);
	notify();
}