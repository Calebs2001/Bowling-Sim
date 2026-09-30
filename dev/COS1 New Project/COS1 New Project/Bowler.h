#pragma once
#include <string>
#include <iostream>

class Bowler
{
private:
	std::string _name;


public:

	// constructor
	Bowler();



	// getters
	std::string GetName(std::string name);


	// setters
	void SetName(std::string name);
};

