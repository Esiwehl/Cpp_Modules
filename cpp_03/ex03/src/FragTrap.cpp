#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << BLUE << "FragTrap " << this->_name << " constructed." << ENDC << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << BLUE << "FragTrap copy constructor called: " << this->_name <<  ENDC << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other){
        ClapTrap::operator=(other);

        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;

         std::cout << BLUE << "FragTrap copy assignment operator called: " << _name << " assigned." << ENDC <<  std::endl;
    }
    return (*this);
}

FragTrap::~FragTrap() {
    std::cout << BLUE << "FragTrap " << this->_name << " destructed."<< ENDC << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (_energyPoints > 0 && _hitPoints > 0){
        std::cout << BLUE << "FragTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage << " points of damage!" << ENDC << std::endl;
        this->_energyPoints--;
    }
}

void FragTrap::highFivesGuys() {
    std::cout << BLUE << "This is here because the subject asked for it\n"
        << "I'm flipping you off <3" << ENDC << std::endl;
}