#include "Fixed.hpp"
#include <string>
#include <iostream>

Fixed::Fixed() : _fpValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& f) : _fpValue(f._fpValue) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& f){
    std::cout << "Copy assignment operator called" << std::endl;
    _fpValue = f._fpValue;
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return _fpValue;
}