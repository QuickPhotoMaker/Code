#pragma once
#include "subject.h"
#include "images.h"
<<<<<<< Updated upstream
#include "daoImage.h"
=======
>>>>>>> Stashed changes
class Controller: public Subject
{
private:
	//ID of the current screen to display
	int currentScreen;
<<<<<<< Updated upstream
	Images images;
	DAOImage daoImage;
=======

	//Collection of images
	Images images;
>>>>>>> Stashed changes
public:
	/*
	 * Constructor
	 */
	Controller();

	/**
	 * Defines the new screen to display
	 * @param value : id of the new screen to display
	 */
	void setScreen(int idView);

	/**
	 * Returns the id of the current displayed screen
	 */
	int getCurrentScreen();
<<<<<<< Updated upstream
	const Images& getImages();
	void addImage(const Image& image);
	void removeImage(const int& index);
=======

	/**
	 * Returns the collection of images
	 */
	const Images& getImages();

	/**
	 * Add an image to the collection
	 * @param image: Image to add
	 */
	void addImage(const Image& image);

	/**
	 * Removes an image from the collection
	 * @param index: Index of the image to remove
	 */
	void removeImage(const int& index);

	/**
	 * Saves an image
	 * @param image: Image to save
	 */
>>>>>>> Stashed changes
	void saveImage(const Image& image) const;
};