#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
    protected:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;

    public:
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        virtual ~ClapTrap();

        int getHitPoints() const;
        std::string getName() const;
        int getEnergyPoints() const;
        int getAttackDamage() const;

        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif