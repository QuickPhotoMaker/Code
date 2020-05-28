#include "viewDelete.h"
#include <iostream>

/**
 * Constructor
 * @param _controller : Controller of the application
 */
ViewDelete::ViewDelete(Controller& _controller)
	: View("SUPPRIMER UNE IMAGE"), controller(_controller)
{
	controller.addObserver(this);
}

//Notification function of the view
void ViewDelete::notify()
{
	if (controller.getCurrentScreen() == 3)
		display();
}

//Displays the view
void ViewDelete::display()
{
	clear();
	View::display();
	for (int iImage = 1; iImage < controller.getImages().size(); ++iImage)
	{
		std::cout << (iImage) << ". " << controller.getImages()[iImage].getPath() << std::endl;
	}

	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "Saisissez le numero de l'image a supprimer ou 0 pour retourner au menu : ";

	int res;
	std::cin.clear();
	std::cin >> res;

	if (res == 0)
		controller.setScreen(res);
	else if (res < controller.getImages().size())
		controller.removeImage(res);
}