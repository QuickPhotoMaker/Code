#pragma once
#include "view.h"
#include "controller.h"

class ViewDerivation: public View
{
private:
	// Controller of the application
	Controller& controller;
public:
	/**
	 * Constructor
	 * @param _controller : Controller of the application
	 */
	ViewDerivation(Controller& _controller);

	/**
	 * Notification function of the view
	 */
	virtual void notify();

	/**
	 * Displays the view
	 */
	virtual void display();

	void derivation();
};