#include <ClapTrap.hpp>

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " was born." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
    std::cout << "ClapTrap " << this->_name << " copy constructed.\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other){
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    std::cout << "ClapTrap " << this->_name << " copy assigned" << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << this->_name << " was destroyed." << std::endl;
}

void ClapTrap::attack(const std::string &target){
    if (_energyPoints > 0 && _hitPoints > 0){
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!\n";
        this->_energyPoints--;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << this->_name << " takes " << amount << " points of damage" << std::endl;
    this->_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    std::cout << this->_name << " heals itself, regaining " << amount << " hit points" << std::endl;
    this->_hitPoints += amount;
    this->_energyPoints--;
}

std::string ClapTrap::getName() const {return _name;}
int ClapTrap::getHitPoints() const {return _hitPoints;}
int ClapTrap::getEnergyPoints() const {return _energyPoints;}
int ClapTrap::getAttackDamage() const {return _attackDamage;}

