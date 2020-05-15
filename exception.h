#pragma once
#include <exception>
#include <string>
class exception : public std::exception
{
public:
	exception(int line, const char* file) noexcept;
	const char* what() const noexcept override;
	virtual const char* GetType() const noexcept;
	int GetLine() const noexcept;
	const std::string& GetFile() const noexcept;
	std::string GetOriginStrng() const noexcept;

private:
	int line;
	std::string file;

protected:
	mutable std::string whatBuffer;
};

