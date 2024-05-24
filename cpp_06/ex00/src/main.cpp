#include <iostream>

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    if (argc == 2)
        ScalarConverter::convert(argv[1]);
    std::cout << "----------------------------\n";
    return 0;
}