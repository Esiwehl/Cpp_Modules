#include "Fixed.hpp"
#include <string>

Fixed::Fixed() : _fpValue(0), _fractionalBit(8) {}

Fixed::Fixed(const Fixed& f) : _fpValue(f._fpValue), _fractionalBit(f._fractionalBit) {}

Fixed& Fixed::operator=(const Fixed& f){
    _fpValue = f._fpValue;
    _fractionalBit = f._fractionalBit;
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}