#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <limits>
#include <ctype.h>

class ScalarConverter {
public:
    static void convert(const std::string& input);

private:
    ScalarConverter() = default;
	ScalarConverter(ScalarConverter const& src) = default;
	ScalarConverter&	operator=(ScalarConverter const& rhs) = default;
	~ScalarConverter() = default;

    static bool isInteger(const std::string& input);
    static bool isFloat(const std::string& input);
    static bool isDouble(const std::string& input);
    static bool isChar(const std::string& input);

    static void convertFromInt(const std::string& input);
    static void convertFromFloat(const std::string& input);
    static void convertFromDouble(const std::string& input);
    static void convertFromChar(const std::string& input);

    static void handleNaN();
    static void handleInf(double value);
};


#endif