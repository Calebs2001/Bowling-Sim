#include <iostream>
#include <string>
#include <iomanip>
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

	const int labelWidth = 8;
	const int frameWidth = 6;

	std::cout << "+" << std::string(labelWidth, '-');
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "+" << std::string(frameWidth, '-');
	}
	std::cout << "+\n";

	std::cout << "|" << std::left << std::setw(labelWidth - 1) << "Frame" << "|";

	for (int i = 1; i <= 10; ++i)
	{
		std::cout << std::right << std::setw(frameWidth) <<  i << "|";
	}
	std::cout << "\n";

	std::cout << "+" << std::string(frameWidth, '-');
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "+" << std::string(frameWidth, '-');
	}
	std::cout << "+\n";

	std::cout << "|" << std::left << std::setw(labelWidth) << "Rolls" << "|";

	for (const Frames& frame : _frames)
	{
		int count = frame.GetRollCount();
		std::string rollsText = "?";

		if (count > 0)
		{
			int first = frame.GetRollPins(0);
			
			if (first == 10)
			{
				rollsText = "X";
			}
			else if (first == 0)
			{
				rollsText = "-";
			}
			else
			{
				rollsText = std::to_string(first);
			}

			if (count >= 2)
			{
				int second = frame.GetRollPins(1);

				if (first != 10)
				{
					if (first + second == 10)
					{
						rollsText += "/";
					}
					else if (second == 0)
					{
						rollsText += "-";
					}
					else
					{
						rollsText += std::to_string(second);
					}
				}
				else
				{
					if (second == 10)
					{
						rollsText += "X";
					}
					else if (second == 0)
					{
						rollsText += "-";
					}
					else
					{
						rollsText += std::to_string(second);
					}
				}
			}
		}

		std::cout << std::right << std::setw(frameWidth) << rollsText << "|";
	}
	std::cout << "\n";

	std::cout << "+" << std::string(labelWidth, '-');
	for (int i = 0; i < 10; i++)
	{
		std::cout << "+" << std::string(frameWidth, '-');
	}
	std::cout << "+\n";

	std::cout << "|" << std::left << std::setw(labelWidth) <<  "Total" << "|";

	for (int i = 0; i < 10; ++i)
	{
		std::string score = scoreReady[i] ? std::to_string(frameScores[i]) : "";

		std::cout << std::right << std::setw(frameWidth) << score << "|";
	}
	std::cout << "\n";

	std::cout << "+" << std::string(labelWidth, '-');
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "+" << std::string(frameWidth, '-');
	}
	std::cout << "+\n";

	std::cout << "Final Total: " << GetTotalScore() << "\n";
}

void Scorecard::AdvanceFrame()
{
	if (_currentFrame < static_cast<int>(_frames.size()) - 1)
	{
		++_currentFrame;
	}
}

