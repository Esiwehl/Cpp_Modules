#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <iostream>

class Fixed{
    private:
        int _rawValue;
        static const int _fractionalBit = 8;
    
        bool isEqualTo(const Fixed& other) const;
        bool isLessThan(const Fixed& other) const;
    public:
        Fixed();
        Fixed(const Fixed& f);
        Fixed& operator=(const Fixed&);
        ~Fixed();

        Fixed(const int num);
        Fixed(const float num);
        int toInt( void ) const;
        float toFloat( void ) const;
        
        bool operator<(const Fixed& other);
        bool operator>(const Fixed& other);
        bool operator<=(const Fixed& other);
        bool operator>=(const Fixed& other);
        bool operator!=(const Fixed& other);
        bool operator==(const Fixed& other);

        Fixed operator+(const Fixed& other);
        Fixed operator-(const Fixed& other);
        Fixed operator*(const Fixed& other);
        Fixed operator/(const Fixed& other);

        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

        static Fixed& min(Fixed& a, Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

        int getRawBits( void ) const;
        void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif