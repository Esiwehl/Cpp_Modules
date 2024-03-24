#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal default constructor called" << std::endl;
    this->_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_type = other._type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "The WrongAnimal makes a sound" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->_type;
}
