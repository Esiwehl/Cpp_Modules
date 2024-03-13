#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : _rawValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& f) : _rawValue(f.getRawBits()) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int intVal) : _rawValue(intVal << _fractionalBit) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatVal) : _rawValue(roundf(floatVal * (1 << _fractionalBit))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& f) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &f)
        _rawValue = f.getRawBits();
    return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

int Fixed::toInt(void) const {
    return _rawValue >> _fractionalBit;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(_rawValue) / (1 << _fractionalBit);
}

int Fixed::getRawBits() const {
    return _rawValue;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}