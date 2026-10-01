#include <iostream>
#include "PinSet.h"

PinSet::PinSet()
{
	for (int i = 1; i <= 10; i++)
	{
		_pins.push_back(Pin(i));
	}
}

bool PinSet::GetIsStanding(int pinNumber) const
{
	if (pinNumber < 1 or pinNumber > 10)
	{
		return false;
	}
	return _pins[pinNumber - 1].GetIsStanding();
}

int PinSet::GetStandingCount() const
{
	int count = 0;

	for (const Pin& pin : _pins)
	{
		if (pin.GetIsStanding())
		{
			++count;
		}
	}
	return count;
}

void PinSet::Reset()
{
	for (Pin& pin : _pins)
	{
		pin.SetPin();
	}
}

void PinSet::KnockDown(int pinNumber)
{
	if (pinNumber >= 1 and pinNumber <= 10)
	{
		_pins[pinNumber - 1].KnockPinDown();
	}
}

void PinSet::Display() const
{
	for (const Pin& pin : _pins)
	{
		if (pin.GetIsStanding())
		{
			std::cout << pin.GetNumber() << " ";
		}
		else
		{
			std::cout << ". ";
		}
	}
	std::cout << "\n";
}

