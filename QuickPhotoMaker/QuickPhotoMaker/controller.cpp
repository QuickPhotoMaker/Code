#include "controller.h"
Controller::Controller()
	:Subject(), currentScreen(0)
<<<<<<< Updated upstream
{
	daoImage.load(images);
}
=======
{}

/**
 * Defines the current screen to display
 * @param value : id of the screen to display
 */
>>>>>>> Stashed changes
void Controller::setScreen(int idView) 
{
	if (idView >= 0 && idView <= 10)
	{
		currentScreen = idView;
		notify();
	}
}

/**
 * Returns the id of the current displayed screen
 */
int Controller::getCurrentScreen() 
{
	return currentScreen;
}
<<<<<<< Updated upstream
/**
 * Returns the collection of complaints
=======

/**
 * Returns the collection of images
>>>>>>> Stashed changes
 */
const Images& Controller::getImages()
{
	return images;
}

/**
<<<<<<< Updated upstream
 * Add a  complaint to the collection
 * @param complaint: Complaint to add
=======
 * Add an image to the collection
 * @param image: Image to add
>>>>>>> Stashed changes
 */
void Controller::addImage(const Image& image)
{
	images.add(image);

<<<<<<< Updated upstream
	daoImage.save(image);

=======
>>>>>>> Stashed changes
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