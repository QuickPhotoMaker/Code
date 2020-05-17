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
	std::cout << "1. Menu" << std::endl << "2. Menu" << std::endl << "..." << std::endl;
	int a;
	std::cin.clear();
	std::cin >> a;
	controller.setScreen(a);
}