#include <iostream>
#include "Fixed.hpp"

#define ENDC "\e[0m"
#define CYAN "\e[36m"
#define YELLOW "\e[33m"
#define GREEN "\e[32m"

void arithmetics(){
	Fixed const a(15);
	Fixed const b(5);
	Fixed c;

	std::cout << YELLOW<< "Time for arithmetics:\t" << ENDC << std::endl;
	c = a + b;
	std::cout << CYAN << "addition is wonderful:\t" << c << ENDC << std::endl;
	c = a - b;
	std::cout << CYAN << "substraction too:\t" << c << ENDC << std::endl;
	c = a * b;
	std::cout << CYAN << "How about a multiplication:\t" << c << ENDC << std::endl;
	c = a / b;
	std::cout << CYAN << "And some division too:\t" << c << ENDC << std::endl;
}

void comparison(){
	Fixed const a(15.54f);
	Fixed const b(5.54f);
	Fixed c(a);

	std::cout << "a = " << a << "\t" << "b = " << b << "\t" << "c = " << c << std::endl;

	// c++;
	// std::cout << "c = " << c << std::endl;

	std::cout << "a < b\t" << ((a < b) ? "True" : "False") << std::endl;
	std::cout << "a > b\t" << ((a > b) ? "True" : "False") << std::endl;

	std::cout << "a == c\t" << ((a == c) ? "True" : "False") << std::endl;
	std::cout << "a != c\t" << ((a != c)  ? "True" : "False")<< std::endl;
}

void subject(){
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
}

int main() {

	// subject();
	// comparison();
	// arithmetics();

	return 0;
}