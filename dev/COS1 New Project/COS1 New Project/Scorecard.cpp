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
	int total = 0;

	for (const Frames& frame : _frames)
	{
		total += frame.GetPinsKnockedDown();
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

