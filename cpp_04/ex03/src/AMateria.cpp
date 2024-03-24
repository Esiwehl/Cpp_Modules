#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : _type("default") {
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type) {
    std::cout << "AMateria type constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
    std::cout << "AMateria assigment operator overload called" << std::endl;
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

void AMateria::use(ICharacter& target) {
    std::cout << "AMateria used on " << target.getName() << std::endl;
}

std::string const & AMateria::getType() const {
    return this->_type;
}

AMateria::~AMateria() {}