#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(){}

Zombie::Zombie(std::string name){
    this->_name = name;
};

void Zombie::setName(std::string name){
    this->_name = name;
};

void Zombie::announce( void ){
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
};

Zombie::~Zombie(){
    std::cout << "Killing " << this->_name << std::endl;
}