#include <iostream>
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << GREEN <<  "ScavTrap " << this->_name << " constructed." << ENDC << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;

    std::cout << GREEN <<  "ScavTrap copy constructor called: " << _name << " copied." << ENDC << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);

        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;

        std::cout << GREEN << "ScavTrap copy assignment operator called: " << _name << " assigned." << ENDC <<  std::endl;
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << GREEN << "ScavTrap " << _name << " destructed." << ENDC << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (_energyPoints > 0 && _hitPoints > 0){
        std::cout << GREEN << "ScavTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage << " points of damage!" << ENDC << std::endl;
        this->_energyPoints--;
    }
}

void ScavTrap::guardGate() {
    std::cout << GREEN << _name << " is now in Gate keeper mode." << ENDC << std::endl;
}