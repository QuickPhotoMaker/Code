#include "viewFiltrage.h"
#include <iostream>

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
	else {
		std::cout << "Saisissez la puissance" << std::endl;
		int puissance;
		std::cin >> puissance;
	}
}