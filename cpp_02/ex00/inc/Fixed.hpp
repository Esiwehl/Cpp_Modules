#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>

class Fixed{
    private:
        int _fpValue;
        static const int _fractionalBit = 8;
    
    public:
        Fixed();
        Fixed(const Fixed& f);  //copy constructor;
        ~Fixed();
        Fixed& operator=(const Fixed&);//copy assignment operator overload;

        int getRawBits( void ) const;
        void setRawBits( int const raw);
};

#endif