#include "viewListe.h"
#include <iostream>
#include <fstream>

/**
 * Constructor
 * @param _controller : Controller of the application
 */
ViewListe::ViewListe(Controller& _controller)
	: View("SELECTIONNER UNE IMAGE"), controller(_controller)
{
	controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewListe::notify()
{
	if (controller.getCurrentScreen() == 1)
		display();
}

/**
 * Displays the view
 */
void ViewListe::display()
{
	clear();
	View::display();

	for (int iComplaint = 0; iComplaint < controller.getImages().size(); ++iComplaint)
	{
		std::cout << (iComplaint + 1) << ". " << controller.getImages()[iComplaint].getPath() << std::endl;
	}

	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "Saisissez le numero de l'image a modifier ou 0 pour retourner au menu : ";

	int res;
	std::cin.clear();
	std::cin >> res;

	if (res == 0)
		controller.setScreen(res);
	else {
		std::ofstream file("selection.txt");
		if (!file.is_open())
			throw "Erreur lors de l'ouverture du fichier";
		else
			file << controller.getImages()[res - 1].getPath();
		file.close();
		controller.setScreen(10);
	}
}