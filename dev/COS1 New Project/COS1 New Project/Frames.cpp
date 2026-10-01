#include "Frames.h"

Frames::Frames(int number) :
	_frameNumber(number)
{

}

Frames::~Frames()
{
	for (Roll* roll : _rolls)
	{
		delete roll;
	}
}

int Frames::GetFrameNumber() const
{
	return _frameNumber;
}

int Frames::GetRollCount() const
{
	return static_cast<int>(_rolls.size());
}

int Frames::GetPinsKnockedDown() const
{
	int total = 0;

	for (const Roll* roll : _rolls)
	{
		total += (*roll).GetPinsKnockedDown();
	}
	return total;
}

void Frames::AddRoll(Roll* roll)
{
	if (roll != nullptr)
	{
		_rolls.push_back(roll);
	}
}

bool Frames::IsStrike() const
{
	if (_rolls.empty())
	{
		return false;
	}

	return (*_rolls[0]).GetPinsKnockedDown() == 10;
}

bool Frames::IsSpare() const
{
	if (_rolls.size() != 2)
	{
		return false;
	}

	return GetPinsKnockedDown() == 10;
}

