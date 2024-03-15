#include "Fixed.hpp"
#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float fx, const float fy) : _x(fx), _y(fy) {}

Point::Point(const Point& p) : _x(p._x), _y(p._y) {}

Point& Point::operator=(Point &p) {
    (void)p;
    return (*this);
}

Point::~Point() {
    // std::cout << "Destructor called" << std::endl;
}

Fixed Point::getX() const {
    return _x;
}

Fixed Point::getY() const {
    return _y;
}

//Non-member function
std::ostream& operator<<(std::ostream& os, const Point& point) {
	os << "(" << point.getX() << "," << point.getY() << ") ";
	return os;
}