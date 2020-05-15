#pragma once
#include <chrono>

class myTimer
{
public:
	myTimer() noexcept;
	float mark() noexcept;
	float peek() const noexcept;
private:
	std::chrono::steady_clock::time_point last;
};

