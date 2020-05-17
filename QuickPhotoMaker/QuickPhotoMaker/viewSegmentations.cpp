#include "viewSegmentations.h"
#include <iostream>

/**
 * Constructor
 * @param _controller : Controller of the application
 */
ViewSegmentations::ViewSegmentations(Controller& _controller)
	: View("SEGMENTATIONS D'IMAGES"), controller(_controller)
{
	controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewSegmentations::notify()
{
	if (controller.getCurrentScreen() == 5)
		display();
}

/**
 * Displays the view
 */
void ViewSegmentations::display()
{
	clear();
	View::display();

	std::cout << "1. Operations de seuillages" << std::endl << "2. Segmentation par croissance de region" << std::endl;

	int a;
	std::cin.clear();
	std::cin >> a;
	if (a == 0)
		controller.setScreen(0);
	else {
		std::cout << "Saisissez la puissance" << std::endl;
		int puissance;
		std::cin >> puissance;
	}
}