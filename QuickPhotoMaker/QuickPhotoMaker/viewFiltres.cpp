#include "viewFiltres.h"
ViewFiltres::ViewFiltres(Controller& _controller)
	:View("MODIFIER L'IMAGE"), controller(_controller)
{
	controller.addObserver(this);
}
void ViewFiltres::notify()
{
	if (controller.getCurrentScreen() == 10)
		display();
}
void ViewFiltres::display()
{
	clear();
	View::display();
	std::cout << "1. Filtrage" << std::endl << "2. Derivation" << std::endl << "3. Operations de morphologie mathematique" << std::endl << "4. Detection de contours" << std::endl << "5. Segmentation d'images" << std::endl;	int a;
	std::cin.clear();
	std::cin >> a;
	if(a>1)
		controller.setScreen(a+3);
}