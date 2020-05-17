#pragma once
#include "controller.h"
#include "viewFiltrage.h"
#include "viewMenu.h"
#include "viewDerivation.h"
#include "viewOMM.h"
#include "viewDetection.h"
class Application
{
private:
	Controller controller;
	ViewMenu viewMenu;
	ViewFiltrage viewFiltrage;
	ViewDerivation viewDerivation;
	ViewOMM viewOMM;
	ViewDetection viewDetection;

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