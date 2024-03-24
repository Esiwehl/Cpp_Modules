#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() {
    _type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
     if (this != &other){
		Animal::operator=(other);
        this->_type = other._type;
    }
    return (*this);
}

void Dog::makeSound() const {
	std::cout << "Bark" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog disappeared into the void." << std::endl;
}