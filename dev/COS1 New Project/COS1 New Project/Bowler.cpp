#include "Bowler.h"

Bowler::Bowler() :
	_name(""), _hand(Hand::Right)
{

}

std::string Bowler::GetName() const
{
	return _name;
}

Bowler::Hand Bowler::GetHand() const
{
	return _hand;
}

void Bowler::SetName(const std::string& newName)
{
	_name = newName;
}

void Bowler::SetHand(Hand newHand)
{
	_hand = newHand;
}
