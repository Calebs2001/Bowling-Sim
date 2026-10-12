#pragma once
#include <string>

class Bowler
{
public:

	enum class Hand
	{
		Left,
		Right
	};

	Bowler();


	std::string GetName() const;

	Hand GetHand() const;

	void SetName(const std::string& newName);

	void SetHand(Hand newHand);


private:
	std::string _name;
	Hand _hand;
};
