#include "viewOMM.h"
#include <iostream>

/**
 * Constructor
 * @param _controller : Controller of the application
 */
ViewOMM::ViewOMM(Controller& _controller)
	: View("OPERATIONS DE MORPHOLOGIE MATHEMATIQUE"), controller(_controller)
{
	controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewOMM::notify()
{
	if (controller.getCurrentScreen() == 3)
		display();
}

/**
 * Displays the view
 */
void ViewOMM::display()
{
	clear();
	View::display();

	std::cout << "1. Dilatation" << std::endl << "2. Erosion" << std::endl;

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