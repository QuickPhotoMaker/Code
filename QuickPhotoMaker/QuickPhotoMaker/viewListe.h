#pragma once
#include "view.h"
#include "controller.h"
#include <string>
class ViewListe: public View
{
private:
	Controller& controller;
	std::string path;
public:
	ViewListe(Controller& _controller);
	virtual void notify();
	virtual void display();
};