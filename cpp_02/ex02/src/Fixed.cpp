#include "Fixed.hpp"
#include <cmath>

// Constructors and Destructor
Fixed::Fixed() : _rawValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intVal) : _rawValue(intVal << _fractionalBit) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatVal) : _rawValue(roundf(floatVal * (1 << _fractionalBit))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& f) : _rawValue(f.getRawBits()) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// Member functions
int Fixed::getRawBits() const {
	return _rawValue;
}

void Fixed::setRawBits(int const raw) {
	_rawValue = raw;
}

float Fixed::toFloat() const {
	return static_cast<float>(_rawValue) / (1 << _fractionalBit);
}

int Fixed::toInt() const {
	return _rawValue >> _fractionalBit;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
	if (other._rawValue == 0) {
		std::cerr << "Division by zero! No, No. We don't do that here" << std::endl;
		return Fixed();
	}
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator=(const Fixed& f) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f){
		this->_rawValue = f.getRawBits();
	}
	return (*this);
}


bool Fixed::isEqualTo(const Fixed& other) const { return _rawValue == other._rawValue; }
bool Fixed::isLessThan(const Fixed& other) const { return _rawValue < other._rawValue; }

bool Fixed::operator==(const Fixed& other) const { return isEqualTo(other); }
bool Fixed::operator!=(const Fixed& other) const { return !isEqualTo(other); }
bool Fixed::operator< (const Fixed& other) const { return isLessThan(other); }
bool Fixed::operator> (const Fixed& other) const { return !isLessThan(other) && !isEqualTo(other); }
bool Fixed::operator<=(const Fixed& other) const { return isLessThan(other) || isEqualTo(other); }
bool Fixed::operator>=(const Fixed& other) const { return !isLessThan(other); }

// Increment and decrement operators
Fixed& Fixed::operator++() { // Pre-increment
	++_rawValue;
	return *this;
}

Fixed Fixed::operator++(int) { // Post-increment
	Fixed temp = *this;
	++(*this);
	return temp;
}

Fixed& Fixed::operator--() { // Pre-decrement
	--_rawValue;
	return *this;
}

Fixed Fixed::operator--(int) { // Post-decrement
	Fixed temp = *this;
	--(*this);
	return temp;
}

// Min|max functions
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}

// Non-member function
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}