#include "controller.h"
#include <fstream>
/*
 * sets the screen to show
 * @param idView: number of the view
 */
Controller::Controller()
	:Subject(), currentScreen(0)
{
	daoImage.load(images);
}

//returns the number of the view
void Controller::setScreen(int idView) 
{
	if (idView >= 0 && idView <= 10)
	{
		currentScreen = idView;
		notify();
	}
}

/*
 * Returns the collection of images
 */
int Controller::getCurrentScreen() 
{
	return currentScreen;
}

/*
 * Returns the collection of images
 */
const Images& Controller::getImages()
{
	return images;
}

/*
 * Add an image to the collection
 * @param image: Image to add
 */
void Controller::addImage(const Image& image)
{
	if (image.getPath() != "") {
		images.add(image);
		daoImage.save(image);
	}
	setScreen(0);
}

/*
 * Removes an image from the collection
 * @param index: Index of the image to remove
 */
void Controller::removeImage(const int& index)
{
	images.remove(index);
	std::ofstream file("paths.txt");
	for (int iImage = 1; iImage < getImages().size(); ++iImage) {
		file << '\n' << getImages()[iImage].getPath();
	}
	file.close();
	notify();
}