#pragma once
#include <string>

namespace Input
{
	int GetNumber(const std::string& prompt, int min, int max);
	std::string GetString(const std::string& prompt);
}

