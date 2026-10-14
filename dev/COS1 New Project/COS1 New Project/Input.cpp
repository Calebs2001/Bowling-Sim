#include "Input.h"
#include <iostream>
#include <stdexcept>
#include <string>

int Input::GetNumber(const std::string& prompt, int min, int max)
{
	while (true)
	{
		std::cout << prompt;
		std::string input;
		std::getline(std::cin, input);
		try
		{
			int number = std::stoi(input);
			if (number >= min and number <= max)
			{
				return number;
			}
			std::cout << "Invalid choice. Please select a number within the avalible choices.\n";
		}
		catch(...)
		{
			std::cout << "Invalid choice. Please select a number within the avalible choices.\n";
		}
	}
}
std::string Input::GetString(const std::string& prompt)
{
	while (true)
	{
		std::cout << prompt;

		std::string input;
		std::getline(std::cin, input);
		if (!input.empty())
		{
			return input;
		}
		std::cout << "There can not be nothing entered. You hvae to have a name.\n";
	}
}
