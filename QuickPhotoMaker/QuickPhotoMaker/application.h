#pragma once
#include "controller.h"
#include "viewFiltrage.h"
#include "viewMenu.h"
#include "viewDerivation.h"
#include "viewOMM.h"
#include "viewDetection.h"
#include "viewAdd.h"
#include "viewDelete.h"
#include "viewListe.h"
#include "viewFiltres.h"
class Application
{
private:
	Controller controller;
	ViewMenu viewMenu;
	ViewFiltrage viewFiltrage;
	ViewDerivation viewDerivation;
	ViewOMM viewOMM;
	ViewDetection viewDetection;
	ViewAdd viewAdd;
	ViewDelete viewDelete;
	ViewListe viewListe;
	ViewFiltres viewFiltres;

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