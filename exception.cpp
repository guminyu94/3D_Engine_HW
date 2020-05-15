#include "exception.h"
#include <sstream>
exception::exception(int line, const char * file) noexcept
	:line(line), file(file)
{}

const char * exception::GetType() const noexcept
{
	return "Chili Exception";
}

const char* exception::what() const noexcept {
	std::ostringstream oss;
	oss << exception::GetType() << std::endl << GetOriginStrng();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

int exception::GetLine() const noexcept
{
	return line;
}

const std::string & exception::GetFile() const noexcept
{
	return file;
}

std::string exception::GetOriginStrng() const noexcept
{
	std::ostringstream oss;
	oss << "[File]" << file << std::endl
	<< "[Line]" << line;
	return oss.str();
}
