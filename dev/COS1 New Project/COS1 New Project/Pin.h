
class Pin
{
private:
	int _pinNumber;
	bool _standing;

public:
	// constructor
	Pin(int pinNumber);

	// getters
	bool GetIsStanding() const;

	int GetNumber() const;

	char GetDisplayPin() const;

	// setters
	void KnockPinDown();

	void SetPin();

};

