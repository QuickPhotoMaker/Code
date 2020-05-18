#pragma once
#include "view.h"
#include "controller.h"
class ViewAdd: public View
{
private:
	Controller& controller;
public:
	ViewAdd(Controller& _controller);
	virtual void notify();
	virtual void display();
};