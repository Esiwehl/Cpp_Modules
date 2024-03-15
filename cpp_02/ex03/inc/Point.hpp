#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point{
    private:
        Fixed const _x;
        Fixed const _y;

    public:
        Point();
        Point(const float fx, const float fy);
        Point(const Point& p);
        Point& operator=(Point& p);
        ~Point();

        Fixed getX() const ;
        Fixed getY() const ;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
std::ostream& operator<<(std::ostream& os, const Point& point);

#endif