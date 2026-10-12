#pragma once
#include <vector>
#include "Frames.h"

class Scorecard
{
private:
	std::vector<Frames> _frames;
	int _currentFrame;

public:
	Scorecard();

	Frames& GetCurrentFrame();

	const std::vector<Frames>& GetFrames() const;

	int GetCurrentFrameNumber() const;

	int GetTotalScore() const;

	void Reset();

	void Display() const;

	void AdvanceFrame();
};

