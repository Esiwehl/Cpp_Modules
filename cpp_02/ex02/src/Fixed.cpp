#include "Fixed.hpp"

// Constructors and Destructor
Fixed::Fixed() : _rawValue(0) {}

Fixed::Fixed(const int intVal) : _rawValue(intVal << _fractionalBit) {}

Fixed::Fixed(const float floatVal) : _rawValue(roundf(floatVal * (1 << _fractionalBit))) {}

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
static Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

static const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

static Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

static const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}

// Non-member function
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}