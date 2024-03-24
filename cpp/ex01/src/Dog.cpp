#include "Animal.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal(), _b(new Brain()){
    _type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), _b(new Brain(*other._b)) {
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
     if (this != &other){
		Animal::operator=(other);
        delete _b;
        _b = new Brain(*other._b);
        this->_type = other._type;
    }
    return (*this);
}

Brain& Dog::getBrain() {
    return *_b;
}

void Dog::makeSound() const {
	std::cout << "Bark" << std::endl;
}

Dog::~Dog() {
    delete _b;
    std::cout << "Dog disappeared into the void." << std::endl;
}