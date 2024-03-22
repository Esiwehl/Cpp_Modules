#include "Animal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal(), _b(new Brain()){
    _type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), _b(new Brain(*other._b)) {
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
     if (this != &other){
		Animal::operator=(other);
        delete _b;
        _b = new Brain(*other._b);
        this->_type = other._type;
    }
    return (*this);
}

Brain& Cat::getBrain() {
    return *_b;
}

void Cat::makeSound() const {
	std::cout << "Purrr" << std::endl;
}

Cat::~Cat() {
    delete _b;
    std::cout << "Cat disappeared into the void." << std::endl;
}
