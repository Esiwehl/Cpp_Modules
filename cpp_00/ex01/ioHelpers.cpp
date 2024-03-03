#include "ioHelpers.hpp"
#include <string>
#include <iostream>

int isInvalidNumber(const std::string& number)
{
	if (number.length() != 10)
		return 1;
	for (size_t idx = 0; idx < number.length(); idx++){
		if (!isdigit(number[idx]))
			return 1;
	}
	return 0;
}

void promptInput(const std::string &prompt, std::string &var, int (*validFunc)(const std::string &number))
{
	do {
		std::cout << prompt;
		std::getline(std::cin, var);
		if (validFunc && validFunc(var)){
			std::cout << "Invalid input. Please try again. Must be 10 digits." << std::endl;
			var.clear();
		}
	} while (var.empty());
}

std::string formatColumn(const std::string input){
	if (input.length() > 10)
		return input.substr(0,9) + ".";
	return std::string(10 - input.length(), ' ') + input;
}
