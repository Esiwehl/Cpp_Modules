#include <iostream>
#include <string>
#include "Weapon.hpp"

Weapon::Weapon( void ) {}

Weapon::Weapon(std::string type) : _type(type) {
    std::cout << "Weapon forged: " << this->getType() << std::endl;
}

Weapon::~Weapon(){
    std::cout << "Weapon destroyed: " << this->getType() << std::endl;
}

void Weapon::setType(std::string type) {
    this->_type = type;
}

std::string Weapon::getType() const {
    return this->_type;
}