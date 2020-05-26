#pragma once
#include <iostream>
#include "controller.h"
#include "observer.h"
#include "view.h"
class ViewMenu: public View
{
private:
	//Controller of the application
	Controller& controller;
public:
	/*
	 * Constructor
	 * @param _controller Application controller
	 */
	ViewMenu(Controller& _controller);

	//Notification function of the view
	void notify();

	//Displays the view
	void display();
};