#include "viewAdd.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <Windows.h>
/**
 * Constructor
 * @param _controller: Application controller
 */
ViewAdd::ViewAdd(Controller& _controller)
	: View("NOUVELLE IMAGE"), controller(_controller)
{
	controller.addObserver(this);
}

//Notification function of the view
void ViewAdd::notify()
{
	if (controller.getCurrentScreen() == 2)
		display();
}

//Displays the view
void ViewAdd::display()
{
	clear();
	View::display();

	std::cout << "Saisissez le parcours de l'image ci-dessous ou laissez vide pour revenir au menu : " << std::endl;

	std::string path;
	std::cin.clear();
	do {
		std::getline(std::cin, path);
	} while (path.empty());

	if (path.empty())
		controller.setScreen(0);
	else
	{
		cv::Mat test = cv::imread(path);
		if (!test.empty()) {
			Image image(path);
			controller.addImage(image);
		}
		else {
			std::cout << "Erreur : image inexistante" << std::endl;
			Sleep(2000);
		}
		controller.setScreen(0);
	}
}