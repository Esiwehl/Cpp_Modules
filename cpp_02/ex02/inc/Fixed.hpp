#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>

class Fixed{
    private:
        int _rawValue;
        static const int _fractionalBit = 8;
    
    public:
        Fixed();
        Fixed(const Fixed& f);
        ~Fixed();

        Fixed(const int num);
        Fixed(const float num);
        int toInt( void ) const;
        float toFloat( void ) const;

        Fixed& operator=(const Fixed&);
        friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed); //What does it mean when you overload the ostream?
        
        friend bool operator<(const Fixed& a, const Fixed& b);
        friend bool operator>(const Fixed& a, const Fixed& b);
        friend bool operator<=(const Fixed& a, const Fixed& b);
        friend bool operator>=(const Fixed& a, const Fixed& b);
        friend bool operator!=(const Fixed& a, const Fixed& b);
        friend bool operator==(const Fixed& a, const Fixed& b);

        friend bool operator+(const Fixed& a, const Fixed& b);
        friend bool operator-(const Fixed& a, const Fixed& b);
        friend bool operator*(const Fixed& a, const Fixed& b);
        friend bool operator/(const Fixed& a, const Fixed& b);

        friend bool operator+(const Fixed& a, const Fixed& b);

        int getRawBits( void ) const;
        void setRawBits(int const raw);
};

#endif