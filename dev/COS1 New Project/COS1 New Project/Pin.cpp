#include "Pin.h"


Pin::Pin(int pinNumber) :
	_pinNumber(pinNumber), _standing(true)
{

}

int Pin::GetNumber() const
{
	return _pinNumber;
}

bool Pin::GetIsStanding() const
{
	return _standing;
}

char Pin::GetDisplayPin() const
{
	if (_standing)
	{
		return '0' + _pinNumber;
	}
	return '.';
}

void Pin::SetPin()
{
	_standing = true;
}

void Pin::KnockPinDown()
{
	_standing = false;
}