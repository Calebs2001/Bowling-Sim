#include <vector>
#include "Pin.h"

class PinSet
{
private:

	std::vector<Pin> _pins;

public:

	PinSet();

	bool GetIsStanding(int pinNumber) const;

	int GetStandingCount() const;
	
	void Reset();

	void KnockDown(int pinNumber);

	void Display() const;
};

