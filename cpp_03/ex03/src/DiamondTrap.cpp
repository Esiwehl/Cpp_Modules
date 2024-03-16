#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
    _name = name;
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap " << _name << " constructed.\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
    *this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        _name = other._name;
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << PURPLE << "DiamondTrap " << this->_name << " destructed.\n" << ENDC << std::endl;
}

void DiamondTrap::attack(const std::string& target){
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << PURPLE << "DiamondTrap name: " << this->_name << ", ClapTrap name: "
        << ClapTrap::_name << ENDC << std::endl;
}