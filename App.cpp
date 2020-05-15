#include "App.h"
#include <iomanip>
#include <sstream> 
App::App()
	:wnd(800,600,"Main Window")
{}

int App::Go()
{
	MSG msg;
	bool gResult;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		doFrame();
	}

	// check if getMessage call itself borked
	if (gResult == -1) {
		throw CHWND_LAST_EXCEPT();
	}

	return msg.wParam;
}

void App::doFrame()
{
	const float t = timer.peek();
	std::ostringstream oss;
	oss << "Time elapsed:" << std::setprecision(1) << std::fixed << t << "s";
	wnd.setTitle(oss.str());
}