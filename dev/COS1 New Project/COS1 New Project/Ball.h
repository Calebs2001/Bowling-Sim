#pragma once

class Ball
{
public:
	enum class Type
	{
		Spare,
		PearlReactive,
		SolidReactive,
		Urethane
	};

	Ball(Type ballType);

	Type GetType() const;

	//Add oil that affects the ball
	int GetOilLevel() const;
	void AddOil(int amount);
	void CleanBall();

	double GetHookEffect() const;

private:
	Type _type;
	int _oilLevel;
	double _urethaneWear;
};
