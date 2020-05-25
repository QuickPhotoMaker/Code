#include "viewFiltrage.h"
#include <iostream>
#include <opencv2/opencv.hpp>

/**
 * Constructor
 * @param _controller : Controller of the application
 */
ViewFiltrage::ViewFiltrage(Controller& _controller)
	: View("FILTRAGE"), controller(_controller)
{
	controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewFiltrage::notify()
{
	if (controller.getCurrentScreen() == 4)
		display();
}

/**
 * Displays the view
 */
void ViewFiltrage::display()
{
	clear();
	View::display();

	std::cout << "1. Filtre median" << std::endl << "2. Filtre gaussien" << std::endl;

	int a;
	std::cin.clear();
	std::cin >> a;

	if (a == 0)
		controller.setScreen(10);
	else if (a == 1)
	{
		std::cout << "Saisissez la puissance" << std::endl;
		int valeur;
		std::cin >> valeur;
		if (valeur < 1)
		{
			valeur = 1;
		}
		if (valeur % 2 == 0)
		{
			valeur += 1;
		}
		std::string selectedImage;
		std::ifstream file("selection.txt");
		if (file.is_open()) {
			while (!file.eof()) {
				std::getline(file, selectedImage);
			}
		}
		file.close();
		cv::Mat image = cv::imread(selectedImage);
		if (image.empty())//on verifie que l'imaeg n'est pas vide
		{
			std::cout << "Could not open or find the image" << std::endl;
			std::cin.get();
		}

		cv::Mat newimage; //on creer la nouvelle image (ici vide)
		cv::medianBlur(image, newimage, valeur);//on applique le blur
		cv::String nameWindow = "Filtrage median";
		cv::namedWindow(nameWindow);
		cv::imshow(nameWindow, newimage);//on affiche l'image modifiée
		cv::waitKey(0);
		cv::destroyAllWindows();
	}
	else if (a==2) {
		std::cout << "Saisissez la puissance" << std::endl;
		int valeur;
		std::cin >> valeur;
		if (valeur < 1)
		{
			valeur = 1;
		}
		if (valeur % 2 == 0)
		{
			valeur += 1;
		}
		std::string selectedImage;
		std::ifstream file("selection.txt");
		if (file.is_open()) {
			while (!file.eof()) {
				std::getline(file, selectedImage);
			}
		}
		file.close();
		cv::Mat image = cv::imread(selectedImage);
		if (image.empty())//on verifie que l'imaeg n'est pas vide
		{
			std::cout << "Could not open or find the image" << std::endl;
			std::cin.get();
		}

		cv::Mat newimage; //on creer la nouvelle image (ici vide)
		cv::GaussianBlur(image, newimage, cv::Size(valeur, valeur), 0, 0, cv::BORDER_DEFAULT);//on applique le blur
		cv::String nameWindow = "Filtre gaussien";
		cv::namedWindow(nameWindow);
		cv::imshow(nameWindow, newimage);//on affiche l'image modifiée
		cv::waitKey(0);
		cv::destroyAllWindows();
	}
}