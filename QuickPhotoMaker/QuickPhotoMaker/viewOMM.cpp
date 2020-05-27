#include "viewOMM.h"
#include <iostream>
#include <opencv2/opencv.hpp>

/**
 * Constructor
 * @param _controller : Controller of the application
 */
ViewOMM::ViewOMM(Controller& _controller)
	: View("OPERATIONS DE MORPHOLOGIE MATHEMATIQUE"), controller(_controller)
{
	controller.addObserver(this);
}

//Notification function of the view
void ViewOMM::notify()
{
	if (controller.getCurrentScreen() == 6)
		display();
}

//Displays the view
void ViewOMM::display()
{
	clear();
	View::display();

	std::cout << "1. Dilatation" << std::endl << "2. Erosion" << std::endl;

	int a;
	std::cin.clear();
	std::cin >> a;

	if (a == 0)
		controller.setScreen(10);

	//Dilatation
	else if (a==1)
	{
		std::string selectedImage;
		std::ifstream file("selection.txt");
		if (file.is_open()) {
			while (!file.eof()) {
				std::getline(file, selectedImage);
			}
		}
		file.close();
		cv::Mat image = cv::imread(selectedImage);
		if (image.empty())
		{
			std::cout << "Could not open or find the image" << std::endl;
			std::cin.get();
		}

		cv::Mat newimage;
		cv::Mat element = cv::Mat();
		cv::dilate(image, newimage, element);
		cv::String nameWindow = "Dilatation";
		cv::namedWindow(nameWindow);
		cv::imshow(nameWindow, newimage);
		cv::waitKey(0);
		cv::destroyAllWindows();
	}

	//Erosion
	else if (a == 2)
	{
		std::string selectedImage;
		std::ifstream file("selection.txt");
		if (file.is_open()) {
			while (!file.eof()) {
				std::getline(file, selectedImage);
			}
		}
		file.close();
		cv::Mat image = cv::imread(selectedImage);
		if (image.empty())
		{
			std::cout << "Could not open or find the image" << std::endl;
			std::cin.get();
		}

		cv::Mat newimage;
		cv::Mat element = cv::Mat();
		cv::erode(image, newimage, element);
		cv::String nameWindow = "Erosion";
		cv::namedWindow(nameWindow);
		cv::imshow(nameWindow, newimage);
		cv::waitKey(0);
		cv::destroyAllWindows();
	}
	controller.setScreen(10);
}