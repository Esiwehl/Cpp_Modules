#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include <string>
#include "Weapon.hpp"

class HumanB{
    private:
        std::string _name;
        Weapon* _weapon;

    public:
        HumanB( void );
        HumanB(std::string name);
        ~HumanB( void );

    void attack();
    void setWeapon(Weapon& weapon);
    std::string getName() const;
};

#endif