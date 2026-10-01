#pragma once
#include <vector>

class Pin
{
private:
	std::vector<Pin> _pin;

public:
	// constructor
	Pin();

	// getters
	bool GetPin(std::vector<Pin> pin);

	// setters
	void SetPin(std::vector<Pin> pin);

};

