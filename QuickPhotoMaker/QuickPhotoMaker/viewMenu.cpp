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
	std::cout << "1. Filtrage" << std::endl << "2. Derivation" << std::endl << "3. Operations de morphologie mathematique" << std::endl << "4. Detection de contours" << std::endl << "5. Segmentation d'images" << std::endl;
	int a;
	std::cin.clear();
	std::cin >> a;
	controller.setScreen(a);
}