#include <iostream>
#include <string>
#include "HumanA.hpp"
#include "Weapon.hpp"


HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {
    std::cout << "Rise little " << this->getName() << ". ";
    std::cout << "Use your " << weapon.getType() << " to slay your enemies" << std::endl;
}

void HumanA::attack(){
    std::cout << _name << " atttacks with their " << _weapon.getType() << std::endl;
}

HumanA::~HumanA(){
    std::cout << _name << " died of mysterious causes " << std::endl;
}

std::string HumanA::getName() const{
    return _name;
}