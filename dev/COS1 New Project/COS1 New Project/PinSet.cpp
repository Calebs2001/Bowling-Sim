#include <iostream>
#include "PinSet.h"
#include "ASCII.h"

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
	std::cout << "\n       PINS REMAINING\n\n";

	int standing = GetStandingCount();

	if (standing == 0)
	{
		setColor(GREEN);
		std::cout << "          ALL PINS CLEARED!\n";
		std::cout << "             \\ O /\n";
		std::cout << "               |\n";
		std::cout << "              / \\\n";
		setColor(WHITE);
	}
	else
	{
		const int pinNumbers[4][4] =
		{
			{ 7, 0, 0, 0 },
			{ 4, 8, 0, 0 },
			{ 2, 5, 9, 0 },
			{ 1, 3, 6, 10 }
		};

		for (int row = 0; row < 4; ++row)
		{
			for (int space = 0; space < (3 - row) * 2; ++space)
			{
				std::cout << ' ';
			}

			for (int col = 0; col <= row; ++col)
			{
				int pinNumber = pinNumbers[row][col];

				if (GetIsStanding(pinNumber))
				{
					setColor(BRIGHT_WHITE);
					std::cout << "O";
				}
				else
				{
					setColor(RED);
					std::cout << "x";
				}

				std::cout << "   ";
			}

			std::cout << '\n';
		}
		std::cout << "\n     Standing: " << standing << " / 10\n";
		setColor(WHITE);
	}
}

