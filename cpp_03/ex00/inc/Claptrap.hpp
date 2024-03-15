#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

#include <string>

class ClapTrap {
    private:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;

    public:
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();

        int getHitPoints();
        std::string getName();
        int getEnergyPoints();
        int getAttackDamage();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

ClapTrap::ClapTrap(std::string name) : _name(name){

}

ClapTrap::ClapTrap(const ClapTrap& other) {
    if (this != &other)
        *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    this->_name = other.getName();
}

ClapTrap::~ClapTrap() {

}

int ClapTrap::getHitPoints() {return _hitPoints;}
std::string ClapTrap::getName() {return _name;}
int ClapTrap::getEnergyPoints() {return _energyPoints;}
int ClapTrap::getAttackDamage() {return _attackDamage;}


#endif