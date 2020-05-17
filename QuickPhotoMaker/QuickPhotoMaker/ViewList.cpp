#include "viewList.h"
#include <iostream>

/**
 * Constructor
 * @param _controller : Controller of the application
 */
ViewList::ViewList(Controller& _controller)
	: View("Liste des doleances"), controller(_controller)
{
	controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewList::notify()
{
	if (controller.getCurrentScreen() == 1)
		display();
}

/**
 * Displays the view
 */
void ViewList::display()
{
	clear();
	View::display();
	/*
	for (int iComplaint = 0; iComplaint < controller.getComplaints().size(); ++iComplaint)
	{
		//TODO
		std::cout << (iComplaint + 1) << ". " << controller.getComplaints()[iComplaint].getMessage() << std::endl;
	}
	*/

	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "Saisissez le numero de la doleance a supprimer ou 0 pour retourner au menu : ";

	int res;
	std::cin.clear();
	std::cin >> res;

	if (res == 0)
		controller.setScreen(res);
	/*
	else
		controller.removeComplaint(res - 1);
		*/
}