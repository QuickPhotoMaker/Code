#pragma once
#include "controller.h"
#include "viewList.h"
#include "viewMenu.h"
class Application
{
private:
	Controller controller;
	ViewMenu viewMenu;
	ViewList viewList;

public:
	/**
	 * Constructor
	 */
	Application();

	/**
	 * Runs the application
	 */
	void run();
};