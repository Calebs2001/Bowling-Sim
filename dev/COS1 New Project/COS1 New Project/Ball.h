#pragma once

class Ball
{
public:
	enum class Type
	{
		Spare,
		Peralreactive,
		SolidReactive,
		Ureathane
	};

	Ball(Type ballType);

	Type GetType() const;


private:
	Type _type;

};
