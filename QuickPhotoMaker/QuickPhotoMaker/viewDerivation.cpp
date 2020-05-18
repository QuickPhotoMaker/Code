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

	int a;
	std::cin.clear();
	std::cin >> a;

	if(a==0)
		controller.setScreen(0);
}