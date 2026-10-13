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
	std::cout << "\n======================== SCORECARD ========================\n";
	std::vector<int> rolls;

	for (const Frames& frame : _frames)
	{
		for (int i = 0; i < frame.GetRollCount(); ++i)
		{
			rolls.push_back(frame.GetRollPins(i));
		}
	}

	std::vector<int> frameScores(10, 0);
	std::vector<bool> scoreReady(10, false);

	int total = 0;
	int rollIndex = 0;
	int rollCount = static_cast<int>(rolls.size());

	for (int frameIndex = 0; frameIndex < 10; ++frameIndex)
	{
		if (rollIndex >= rollCount)
			break;

		int firstRoll = rolls[rollIndex];

		if (firstRoll == 10)
		{
			if (rollIndex + 2 >= rollCount)
				break;

			total += 10 + rolls[rollIndex + 1] + rolls[rollIndex + 2];
			++rollIndex;
		}
		else
		{
			if (rollIndex + 1 >= rollCount)
				break;

			int secondRoll = rolls[rollIndex + 1];

			if (firstRoll + secondRoll == 10)
			{
				if (rollIndex + 2 >= rollCount)
					break;

				total += 10 + rolls[rollIndex + 2];
			}
			else
			{
				total += firstRoll + secondRoll;
			}

			rollIndex += 2;
		}
		frameScores[frameIndex] = total;
		scoreReady[frameIndex] = true;
	}
	for (const Frames& frame : _frames)
	{
		int frameNumber = frame.GetFrameNumber();
		int count = frame.GetRollCount();

		std::cout << "\nFrame " << frameNumber << ": ";

		if (count == 0)
		{
			std::cout << "-";
		}
		else
		{
			int first = frame.GetRollPins(0);

			if (first == 10)
			{
				std::cout << "X (Strike)";
			}
			else
			{
				std::cout << first;

				if (count >= 2)
				{
					int second = frame.GetRollPins(1);

					if (first + second == 10)
						std::cout << " / (Spare)";
					else
						std::cout << " " << second;
				}
			}
		}
		if (scoreReady[frameNumber - 1])
			std::cout << " | Score: " << frameScores[frameNumber - 1];
		else
			std::cout << " | Score: Pending";
	}
	std::cout << "\n-----------------------------------------------------------\n";
	std::cout << "Final Total: " << GetTotalScore() << "\n";
}

void Scorecard::AdvanceFrame()
{
	if (_currentFrame < static_cast<int>(_frames.size()) - 1)
	{
		++_currentFrame;
	}
}

