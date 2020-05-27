#pragma once
#include "view.h"
#include "controller.h"
class ViewAdd: public View
{
private:
	//Controller of the application
	Controller& controller;
public:
	/**
	 * Constructor
	 * @param _controller: Application controller
	 */
	ViewAdd(Controller& _controller);

	//Notification function of the view
	virtual void notify();

	//Displays the view
	virtual void display();
};