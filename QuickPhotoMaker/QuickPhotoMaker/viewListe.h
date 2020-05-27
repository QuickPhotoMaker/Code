#pragma once
#include "view.h"
#include "controller.h"
#include <string>
class ViewListe: public View
{
private:
	//Controller of the application
	Controller& controller;

	//path of the selected image
	std::string path;
public:
	/*
	 * Constructor
	 * @param _controller: Controller of the application
	 */
	ViewListe(Controller& _controller);

	//Notification function of the view
	virtual void notify();

	//Displays the view
	virtual void display();
};