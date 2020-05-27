#pragma once
#include "view.h"
#include "controller.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

class ViewDetection : public View
{
private:
	// Controller of the application
	Controller& controller;
public:
	/**
	 * Constructor
	 * @param _controller : Controller of the application
	 */
	ViewDetection(Controller& _controller);

	//Notification function of the view
	virtual void notify();

	//Displays the view
	virtual void display();

};