#include "Ball.h"

class Roll
{
public:
	enum class ThrowStyle
	{
		Straight,
		Hook
	};

	Roll(Ball* selectedBall, ThrowStyle selectedStyle);

	Ball* GetBall() const;

	ThrowStyle GetStyle() const;

	int GetPinsKnockedDown() const;

	void SetPinsKnockedDown(int pins);

private:
	Ball* _ball;
	ThrowStyle _style;
	int _pinsKnockedDown;
};

