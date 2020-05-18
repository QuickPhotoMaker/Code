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

/**
 * Notification function of the view
 */
void ViewDelete::notify()
{
	if (controller.getCurrentScreen() == 3)
		display();
}

/**
 * Displays the view
 */
void ViewDelete::display()
{
	clear();
	View::display();
	for (int iImage = 0; iImage < controller.getImages().size(); ++iImage)
	{
		//TODO
		std::cout << (iImage + 1) << ". " << controller.getImages()[iImage].getPath() << std::endl;
	}

	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "Saisissez le numero de l'image a supprimer ou 0 pour retourner au menu : ";

	int res;
	std::cin.clear();
	std::cin >> res;

	if (res == 0)
		controller.setScreen(res);
	else {
		controller.removeImage(res - 1);
		std::ofstream file("paths.txt");
		for (int iImage = 0; iImage < controller.getImages().size(); ++iImage) {
			if (iImage != controller.getImages().size() - 1)
				file << controller.getImages()[iImage].getPath() << '\n';
			else
				file << controller.getImages()[iImage].getPath();
		}
		file.close();
	}
}