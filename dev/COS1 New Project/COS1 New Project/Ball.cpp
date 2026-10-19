#include "Ball.h"

Ball::Ball(Type ballType) :
	_type(ballType), _oilLevel(0), _urethaneWear(0.0)
{

}

Ball::Type Ball::GetType() const
{
	return _type;
}

int Ball::GetOilLevel() const
{
	return _oilLevel;
}

void Ball::AddOil(int amount)
{
	_oilLevel += amount;

	if (_oilLevel > 100)
	{
		_oilLevel = 100;
	}
	if (_oilLevel < 0)
	{
		_oilLevel = 0;
	}
}

void Ball::CleanBall()
{
	_oilLevel = 0;

	if (_type == Type::Urethane)
	{
		_urethaneWear += 0.03;

		if (_urethaneWear > 0.30)
		{
			_urethaneWear = 0.30;
		}
	}
}

double Ball::GetHookEffect() const
{
	double effect = 1.0 - (_oilLevel / 200.0);

	if (_type == Type::Urethane)
	{
		effect *= (1.0 - _urethaneWear);
	}
	return effect;
}
