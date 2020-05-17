#include "application.h"

/**
 * Constructor
 */
Application::Application()
    : controller(), viewMenu(controller), viewList(controller)
{
}

/**
 * Runs the application
 */
void Application::run()
{
    controller.notify();
}