#include "viewDerivation.h"
#include <iostream>

/**
 * Constructor
 * @param _controller : Controller of the application
 */
ViewDerivation::ViewDerivation(Controller& _controller)
	: View("DERIVATION"), controller(_controller)
{
	controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewDerivation::notify()
{
	if (controller.getCurrentScreen() == 5)
		display();
}

/**
 * Displays the view
 */
void ViewDerivation::display()
{
	clear();
	View::display();

	std::cout << "Calcul du gradient dans l'image en cours..." << std::endl;

	derivation();

	int a;
	std::cin.clear();
	std::cin >> a;

	if(a==0)
		controller.setScreen(0);
}

void ViewDerivation::derivation()
{
	std::string selectedImage;
	std::ifstream file("image.txt");
	if (file.is_open()) {
		while (!file.eof()) {
			std::getline(file, selectedImage);
		}
	}
	cv::Mat src = cv::imread(selectedImage);
	cv::GaussianBlur(src, src, cv::Size(3, 3), 0, 0, cv::BORDER_DEFAULT);
	cv::cvtColor(src, src, cv::COLOR_BGR2GRAY);
	cv::Mat grad_x, grad_y;
	cv::Sobel(src, grad_x, CV_16S, 1, 0, 3, 1, 0, cv::BORDER_DEFAULT);
	cv::Sobel(src, grad_y, CV_16S, 0, 1, 3, 1, 0, cv::BORDER_DEFAULT);
	cv::convertScaleAbs(grad_x, grad_x);
	cv::convertScaleAbs(grad_y, grad_y);
	cv::addWeighted(grad_x, 0.5, grad_y, 0.5, 0, src);
	cv::imshow("Derivation", src);
}