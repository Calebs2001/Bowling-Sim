#include "Roll.h"

Roll::Roll(Ball* selectedBall, ThrowStyle selectedStyle) :
	_ball(selectedBall), _style(selectedStyle), _pinsKnockedDown(0)
{

}

Ball* Roll::GetBall() const
{
	return _ball;
}

Roll::ThrowStyle Roll::GetStyle() const
{
	return _style;
}

int Roll::GetPinsKnockedDown() const
{
	return _pinsKnockedDown;
}

void Roll::SetPinsKnockedDown(int pins)
{
	_pinsKnockedDown = pins;
}

