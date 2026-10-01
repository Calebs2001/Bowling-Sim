#include <vector>
#include "Roll.h"


class Frames
{
private:
	int _frameNumber;
	std::vector<Roll*> _rolls;

public:
	Frames(int number);

	~Frames();

	int GetFrameNumber() const;

	int GetRollCount() const;

	int GetPinsKnockedDown() const;

	void AddRoll(Roll* roll);

	bool IsStrike() const;

	bool IsSpare() const;
};

