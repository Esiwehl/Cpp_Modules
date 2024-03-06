#include <iostream>
#include <string>
#include "HumanB.hpp"
#include "Weapon.hpp"

#define RESET "\e[0m"
#define	CYAN "\e[36m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"

HumanB::HumanB(std::string name) : _name(name), _weapon(nullptr) {
    std::cout << "Rise little " << this->getName() << ". ";
    std::cout << "Be careful, your hands will only get you so far." << std::endl;
}

HumanB::~HumanB(){
    std::cout << _name << " died of mysterious causes " << std::endl;
}

void HumanB::attack(){
    if (_weapon != nullptr) {
        std::cout << _name << " atttacks with their " << _weapon->getType() << std::endl;
    }
    else {
        std::cout << _name << " attacks with bare hands" << std::endl;
    }
}

std::string HumanB::getName() const{
    return this->_name;
}

void HumanB::setWeapon(Weapon& weapon) {
    this->_weapon = &weapon;
}