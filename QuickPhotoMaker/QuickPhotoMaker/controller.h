#pragma once
#include "subject.h"
#include "images.h"
#include "daoImage.h"
class Controller: public Subject
{
private:
	//number of the view
	int currentScreen;

	Images images;
	DAOImage daoImage;
public:
	//Constructor
	Controller();

	/*
	 * sets the screen to show
	 * @param idView: number of the view
	 */
	void setScreen(int idView);

	//returns the number of the view
	int getCurrentScreen();

	/*
	 * Returns the collection of images
	 */
	const Images& getImages();

	/*
     * Add an image to the collection
	 * @param image: Image to add
	 */
	void addImage(const Image& image);

	/*
	 * Removes an image from the collection
	 * @param index: Index of the image to remove
	 */
	void removeImage(const int& index);
};