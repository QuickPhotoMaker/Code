#include "viewDetection.h"
#include <iostream>

/**
 * Constructor
 * @param _controller : Controller of the application
 */
ViewDetection::ViewDetection(Controller& _controller)
	: View("DETECTION DE CONTOURS"), controller(_controller)
{
	controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewDetection::notify()
{
	if (controller.getCurrentScreen() == 4)
		display();
}

/**
 * Displays the view
 */
void ViewDetection::display()
{
	clear();
	View::display();

	std::cout << "Detection de contours en cours..." << std::endl;

	int a;
	std::cin.clear();
	std::cin >> a;
	if (a == 0)
		controller.setScreen(0);
}