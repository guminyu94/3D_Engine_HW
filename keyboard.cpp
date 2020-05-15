#include "keyboard.h"

bool keyboard::keyIsPressed(unsigned char keyCode) const noexcept
{
	return keyStates[keyCode];
}

keyboard::event keyboard::readKey() noexcept
{
	if (keyBuffer.size() > 0u) {
		// read event and remove one oldest element 
		keyboard::event e = keyBuffer.front();
		keyBuffer.pop();
		return e;
	}
	else 
	{
		// if no event in the buffer then return empty
		return keyboard::event();
	}
}


bool keyboard::keyIsEmpty() const noexcept
{
	// if the q is empty
	return keyBuffer.empty();
}

void keyboard::flushKey() noexcept
{
}

char keyboard::readChar() noexcept
{
	if (charBuffer.size() > 0u) {
		// read event and remove one oldest element 
		unsigned char charCode = charBuffer.front();
		charBuffer.pop();
		return charCode;
	}
	else
	{
		// if no event in the buffer then return empty
		return 0;
	}
}

bool keyboard::charIsEmpty() const noexcept
{
	// return if charBuffer is empty
	return charBuffer.empty();
}

void keyboard::flushChar() noexcept
{
	// empty the key q
	keyBuffer = std::queue<keyboard::event>();
}

void keyboard::flush() noexcept
{
	flushKey();
	flushChar();
}

void keyboard::enableAutoRepeat() noexcept
{
	autoRepeatEnabled = true;
}

void keyboard::disableAutoRepeat() noexcept
{
	autoRepeatEnabled = false;
}

bool keyboard::autoRepeatIsEnabled() const noexcept
{
	return autoRepeatEnabled;
}

void keyboard::onKeyPressed(unsigned char keyCode) noexcept
{
	// update the keybuffer and keyStates
	keyStates[keyCode] = true;
	keyBuffer.push(keyboard::event(keyboard::event::Type::Press, keyCode));
	trimBuffer(keyBuffer);
}

void keyboard::onKeyReleased(unsigned char keyCode) noexcept
{
	keyStates[keyCode] = false;
	keyBuffer.push(keyboard::event(keyboard::event::Type::Release, keyCode));
	trimBuffer(keyBuffer);
}

void keyboard::onChar(char character) noexcept
{
	charBuffer.push(character);
	trimBuffer(charBuffer);
}

void keyboard::clearState() noexcept
{
	keyStates.reset();
}

template<typename T>
void keyboard::trimBuffer(std::queue<T>& buffer) noexcept
{
	while (buffer.size() > bufferSize)
	{
		buffer.pop();
	}
}
