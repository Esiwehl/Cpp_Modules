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
        Fixed& operator=(const Fixed&);
        Fixed(const int num);
        Fixed(const float num);

        ~Fixed();

        int toInt( void ) const;
        float toFloat( void ) const;

        int getRawBits( void ) const;
        void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif