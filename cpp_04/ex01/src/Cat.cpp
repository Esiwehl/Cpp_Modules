#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat() : _b(new Brain()){
    _type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
     if (this != &other){
		Animal::operator=(other);
        this->_type = other._type;
    }
    return (*this);
}

void Cat::makeSound() const {
	std::cout << "Purrr" << std::endl;
}

Cat::~Cat() {
    delete _b;
    std::cout << "Cat disappeared into the void." << std::endl;
}
