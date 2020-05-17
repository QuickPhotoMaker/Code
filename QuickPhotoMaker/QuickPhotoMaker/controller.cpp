#include "controller.h"
Controller::Controller()
	:Subject(), currentScreen(0)
{}
void Controller::setScreen(int idView) 
{
	if (idView >= 0 && idView <= 9)
	{
		currentScreen = idView;
		notify();
	}
}
int Controller::getCurrentScreen() 
{
	return currentScreen;
}