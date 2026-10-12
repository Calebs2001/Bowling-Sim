#include "Ball.h"

Ball::Ball(Type ballType) :
	_type(ballType)
{

}

Ball::Type Ball::GetType() const
{
	return _type;
}

