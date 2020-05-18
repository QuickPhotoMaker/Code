#include "application.h"

/**
 * Constructor
 */
Application::Application()
    : controller(), viewMenu(controller), viewFiltrage(controller), viewDerivation(controller), viewOMM(controller), viewDetection(controller), viewAdd(controller), viewDelete(controller), viewListe(controller), viewFiltres(controller)
{
}

/**
 * Runs the application
 */
void Application::run()
{
    controller.notify();
}