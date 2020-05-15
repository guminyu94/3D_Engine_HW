#pragma once
#include "Window.h"
#include "timer.h"
class App
{
public:
	App();

	// master frame / message loop
	// new
	int Go();
private:

	void doFrame();
private:
	Window wnd;
	myTimer timer;
};

