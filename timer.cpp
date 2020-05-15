#include "timer.h"

using namespace std::chrono;
myTimer::myTimer() noexcept
{
	// record the starting time
	last = steady_clock::now();
}

float myTimer::mark() noexcept
{
	const auto old = last;
	// update last
	last = steady_clock::now();
	// return the frame time
	const duration<float> frameTime = last - old;
	return frameTime.count();
}

float myTimer::peek() const noexcept
{
	return duration<float>(steady_clock::now() - last).count();
}
