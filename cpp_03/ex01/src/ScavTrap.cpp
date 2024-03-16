#include <iostream>
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << this->_name << " constructed.\n";
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _name << " destructed.\n";
}

void ScavTrap::attack(const std::string& target) {
    if (_energyPoints > 0 && _hitPoints > 0){
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
        this->_energyPoints--;
    }
}

void ScavTrap::guardGate() {
    std::cout << _name << " is now in Gate keeper mode.\n";
}