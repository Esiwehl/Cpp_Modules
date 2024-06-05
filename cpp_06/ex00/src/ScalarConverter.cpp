#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>
#include <ctype.h>

void ScalarConverter::convert(const std::string& input) {
    if (isInteger(input)) {
        convertFromInt(input);
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

bool ScalarConverter::isDouble(const std::string& input) {
    std::istringstream iss(input);
    double n;
    iss >> std::noskipws >> n;
    std::cout << n << std::endl;
    return iss.eof() && !iss.fail(); 
}

bool ScalarConverter::isChar(const std::string& input) {
    return input.length() == 1;
}

void ScalarConverter::convertFromInt(const std::string& input) {
    int value = std::stoi(input);
    std::cout << "char: ";
    if (isprint(value))
        std::cout << static_cast<char>(value);
    else
        std::cout << "Non displayable";
    std::cout << std::endl;

    std::cout << "int: " << value << std::endl;
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertFromDouble(const std::string& input) {
    double value = std::stod(input);
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: ";
    if (value > INT16_MAX || value < INT16_MIN) 
        std::cout << "Some type of flow.";
    else
        std::cout << static_cast<int>(value);
    std::cout << std::endl;

    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << value << std::endl;
}

void ScalarConverter::convertFromChar(const std::string& input) {
    char value = input[0];
    std::cout << "char: ";
    if (isprint(value))
        std::cout << static_cast<char>(value);
    else
        std::cout << "Non displayable";
    std::cout << std::endl;

    std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}
