#pragma once
#include <queue>
#include <bitset>

class keyboard
{
	friend class Window;
public:
	class event
	{
	public:
		enum class Type
		{
			Press,
			Release,
			Invalid
		};
	private:
		Type type;
		unsigned char code;
	public:
		event() noexcept :type(Type::Invalid), code(0u) {};
		event(Type type, unsigned char code) noexcept : type(type), code(code) {};
		bool IsPress() const noexcept
		{
			return type == Type::Press;
		}
		bool IsRelease() const noexcept
		{
			return type == Type::Release;
		}
		bool IsValid() const noexcept
		{
			return type != Type::Invalid;
		}
		unsigned char GetCode() const noexcept
		{
			return code;
		}
	};
	keyboard() = default;
	keyboard(const keyboard&) = delete;
	keyboard& operator= (const keyboard&) = delete;
	// key event
	bool keyIsPressed(unsigned char keynode) const noexcept;
	keyboard::event readKey() noexcept;
	bool keyIsEmpty() const noexcept;
	void flushKey() noexcept;
	// char event
	char readChar() noexcept;
	bool charIsEmpty() const noexcept;
	void flushChar() noexcept;
	void flush() noexcept;
	// autorepeat control
	void enableAutoRepeat() noexcept;
	void disableAutoRepeat() noexcept;
	bool autoRepeatIsEnabled() const noexcept;

private:
	void onKeyPressed(unsigned char keycode) noexcept;
	void onKeyReleased(unsigned char keycode) noexcept;
	void onChar(char character) noexcept;
	void clearState() noexcept;
	template<typename T>
	static void trimBuffer(std::queue<T>& buffer) noexcept;
private:
	static constexpr unsigned int nKeys = 256u;
	static constexpr unsigned int bufferSize = 16u;
	bool autoRepeatEnabled = false;
	std::bitset<nKeys> keyStates;
	std::queue<keyboard::event> keyBuffer;
	std::queue<char> charBuffer;
};

