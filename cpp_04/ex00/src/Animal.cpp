#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type){
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal assignment operator called" << std::endl;
     if (this != &other){
        this->_type = other._type;
    }
    return (*this);
}

std::string Animal::getType() const {return _type;}

void Animal::makeSound() const {
	std::cout << "the sound of silencee" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal disappeared into the void." << std::endl;
}