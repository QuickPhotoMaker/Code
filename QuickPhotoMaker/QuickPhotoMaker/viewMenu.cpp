#include "viewMenu.h"
ViewMenu::ViewMenu(Controller& _controller)
	:View("MENU"), controller(_controller)
{
	controller.addObserver(this);
}
void ViewMenu::notify()
{
	if (controller.getCurrentScreen() == 0)
		display();
}
void ViewMenu::display()
{
	clear();
	View::display();
	std::cout << "1. Images" << std::endl << "2. Ajouter une Image" << std::endl << "3. Supprimer une image" << std::endl;
	int a;
	std::cin.clear();
	std::cin >> a;
	if(a<=3)
		controller.setScreen(a);
}