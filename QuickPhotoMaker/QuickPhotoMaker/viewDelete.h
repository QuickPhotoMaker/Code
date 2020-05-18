#pragma once
#include "view.h"
#include "controller.h"
#include "fstream"

class ViewDelete:public View
{
private:
	Controller& controller;
public:
	/**
	 * Constructor
	 * @param _controller : Controller of the application
	 */
	ViewDelete(Controller& _controller);

	/**
	 * Notification function of the view
	 */
	virtual void notify();

	/**
	 * Displays the view
	 */
	virtual void display();
};