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


private:
	Type _type;

};
