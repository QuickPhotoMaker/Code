#include "viewFiltres.h"
#include <fstream>
#include <opencv2/opencv.hpp>
/*
 * Constructor
 * @param _controller Application controller
 */
ViewFiltres::ViewFiltres(Controller& _controller)
	:View("MODIFIER L'IMAGE"), controller(_controller)
{
	controller.addObserver(this);
}

//Notification function of the view
void ViewFiltres::notify()
{
	if (controller.getCurrentScreen() == 10)
		display();
}

//Displays the view
void ViewFiltres::display()
{
	clear();
	View::display();
	std::string selection;
	std::ifstream file("selection.txt");
	if (file.is_open()) {
		while (!file.eof()) {
			std::getline(file, selection);
		}
	}
	file.close();
	std::cout << selection << std::endl << std::endl;
	std::cout << "1. Filtrage" << std::endl << "2. Derivation" << std::endl << "3. Operations de morphologie mathematique" << std::endl << "4. Detection de contours" << std::endl << "5. Segmentation d'images" << std::endl << std::endl << "6. Afficher l'image originale" << std::endl << "7. Retour au menu" << std::endl;
	int a;
	std::cin.clear();
	std::cin >> a;
	if (a >= 1) {
		if (a == 7)
			controller.setScreen(0);
		else if (a == 6) {
			cv::Mat image = cv::imread(selection);
			cv::namedWindow(selection);
			cv::imshow(selection, image);
			cv::waitKey(0);
		}
		else
			controller.setScreen(a + 3);
	}
}