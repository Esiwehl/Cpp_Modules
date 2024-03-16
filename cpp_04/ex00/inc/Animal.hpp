#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
    protected:
        std::string _type;
    
    public:
        Animal(std::string& type);
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        ~Animal();
};

Animal::Animal(std::string& type) : _type(type) {
    std::cout << "Animal of type: " << this->_type << " was created." << std::endl;
}

Animal::Animal(const Animal& other) {
    if (this != &other){
        _type = other._type;
    }
}

Animal::~Animal() {
    std::cout << _type << " disappeared into the void." << std::endl;
}

#endif