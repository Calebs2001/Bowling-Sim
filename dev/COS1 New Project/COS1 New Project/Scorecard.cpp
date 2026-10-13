#include <iostream>
#include "Scorecard.h"

Scorecard::Scorecard() :
	_currentFrame(0)
{
	Reset();
}

Frames& Scorecard::GetCurrentFrame()
{
	return _frames[_currentFrame];
}

const std::vector<Frames>& Scorecard::GetFrames() const
{
	return _frames;
}

int Scorecard::GetCurrentFrameNumber() const
{
	return _currentFrame + 1;
}

int Scorecard::GetTotalScore() const
{
	std::vector<int> rolls;

	for (const Frames& frame : _frames)
	{
		for (int i = 0; i < frame.GetRollCount(); ++i)
		{
			rolls.push_back(frame.GetRollPins(i));
		}
	}

	int total = 0;
	int rollIndex = 0;
	const int rollCount = static_cast<int>(rolls.size());

	for (int frameIndex = 0; frameIndex < 10; ++frameIndex)
	{
		if (rollIndex >= rollCount)
		{
			break;
		}

		int firstRoll = rolls[rollIndex];

		if (firstRoll == 10)
		{
			if (rollIndex + 2 >= rollCount)
			{
				break;
			}

			total += 10 + rolls[rollIndex + 1] + rolls[rollIndex + 2];

			++rollIndex;
		}
		else
		{
			if (rollIndex + 1 >= rollCount)
			{
				break;
			}

			int secondRoll = rolls[rollIndex + 1];

			if (firstRoll + secondRoll == 10)
			{
				if (rollIndex + 2 >= rollCount)
				{
					break;
				}

				total += 10 + rolls[rollIndex + 2];
			}
			else
			{
				total += firstRoll + secondRoll;
			}

			rollIndex += 2;
		}

	}
	return total;
}

void Scorecard::Reset()
{
	_frames.clear();

	for (int i = 1; i <= 10; i++)
	{
		_frames.push_back(Frames(i));
	}

	_currentFrame = 0;
}

void Scorecard::Display() const
{
	std::cout << "\n=========================\n";
	std::cout << "        SCORECARD\n";
	std::cout << "=========================\n";

	for (const Frames& frame : _frames)
	{
		std::cout << "Frame " << frame.GetFrameNumber() << ": " << frame.GetPinsKnockedDown() << " pins\n";
	}

	std::cout << "-------------------------\n";
	std::cout << "Total Score: " << GetTotalScore() << "\n";
}

void Scorecard::AdvanceFrame()
{
	if (_currentFrame < static_cast<int>(_frames.size()) - 1)
	{
		++_currentFrame;
	}
}

