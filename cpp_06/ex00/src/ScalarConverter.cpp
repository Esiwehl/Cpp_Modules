#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cmath>
#include <ctype.h>

bool isNumberChar(char c) {
	return (c >= '0' && c <= '9') || c == '.' || c == '+' || c == '-';
}

int determinePrecision(const std::string& input) {
	size_t pos = input.find('.');
	if (pos == std::string::npos) {
		return 0;
	}

	if (input.back() == 'f') {
		return static_cast<int>(input.length() - pos - 2);
	}
	return static_cast<int>(input.length() - pos - 1);
}

void ScalarConverter::convert(const std::string& input) {
	if (isInteger(input)) {
		convertFromInt(input);
	}else if (isFloat(input)) {
		convertFromFloat(input);
	} else if (isDouble(input)) {
		convertFromDouble(input);
	} else if (isChar(input)) {
		convertFromChar(input);
	} else {
		try {
			double value = std::stod(input);

			if (std::isnan(value)) {
				handleNaN();
			} else if (std::isinf(value))
				handleInf(value);
		} catch (const std::exception& e) {
			std::cout << "Invalid input for conversion." << std::endl;
		}
	}
}

void ScalarConverter::handleNaN() {
	  std::cout << "char: impossible" << std::endl;
	  std::cout << "int: impossible" << std::endl;
	  std::cout << "float: nanf" << std::endl;
	  std::cout << "double: nan" << std::endl;
}

void ScalarConverter::handleInf(double value) {
	  std::string sign = (value < 0) ? "-" : "+";
	  std::cout << "char: impossible" << std::endl;
	  std::cout << "int: impossible" << std::endl;
	  std::cout << "float: " << sign << "inff" << std::endl;
	  std::cout << "double: " << sign << "inf" << std::endl;
}

bool ScalarConverter::isInteger(const std::string& input) {
	std::istringstream iss(input);
	int n;
	iss >> std::noskipws >> n;
	return iss.eof() && !iss.fail(); 
}

bool ScalarConverter::isFloat(const std::string& input) {
	bool hasDecimal = false;
	size_t len = input.length();
	if (len == 0) return false;

	if (input.back() != 'f') return false;

	for (size_t i = 0; i < len - 1; ++i) {
		char c = input[i];
		if (c == '.') {
			if (hasDecimal) return false;
			hasDecimal = true;
		} else if (!isNumberChar(c)) {
			return false;
		}
	}
	return hasDecimal;
}


bool ScalarConverter::isDouble(const std::string& input) {
   bool hasDecimal = false;
	for (char c : input) {
		if (c == '.') {
			hasDecimal = true;
		} else if (!isNumberChar(c) || c == 'f') {
			return false;
		}
	}

	return hasDecimal;
}

bool ScalarConverter::isChar(const std::string& input) {
	return input.length() == 1;
}

void ScalarConverter::convertFromInt(const std::string& input) {
	int value = std::stoi(input);
	std::cout << "char: ";
	if (isprint(value))
		std::cout << "\'" << static_cast<char>(value) << "\'";
	else
		std::cout << "Non displayable";
	std::cout << std::endl;

	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void ScalarConverter::convertFromFloat(const std::string& input) {
	float value = std::stof(input);
	std::cout << "char: ";
	if (std::floor(value) != value) {
		std::cout << "impossible";
	} else if (isprint(static_cast<int>(value))) {
		std::cout << "\'" << static_cast<char>(value) << "\'";
	} else {
		std::cout << "Non displayable";
	}
	std::cout << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;

	std::cout << std::fixed << std::setprecision(determinePrecision(input));

	std::cout << "float: " << value << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertFromDouble(const std::string& input) {
	double value = std::stod(input);
	std::cout << "char: ";
	 if (std::floor(value) != value) {
		std::cout << "impossible";
	} else if (isprint(static_cast<int>(value))) {
		std::cout << "\'" << static_cast<char>(value) << "\'";
	} else {
		std::cout << "Non displayable";
	}
	std::cout << std::endl;

	std::cout << "int: ";
	if (value > INT16_MAX || value < INT16_MIN) 
		std::cout << "Some type of flow.";
	else
		std::cout << static_cast<int>(value);
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(determinePrecision(input));

	std::cout << "float: " << static_cast<float>(value) << 'f' << std::endl;
	std::cout << "double: " << value << std::endl;
}

void ScalarConverter::convertFromChar(const std::string& input) {
	char value = input[0];
	std::cout << "char: \'";
	if (isprint(value))
		std::cout << static_cast<char>(value) << "\'";
	else
		std::cout << "Non displayable";
	std::cout << std::endl;

	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}
