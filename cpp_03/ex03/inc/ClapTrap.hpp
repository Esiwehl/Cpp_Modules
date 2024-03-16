#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# define CYAN "\e[0;36m"
# define PURPLE "\e[0;35m"
# define BLUE "\e[0;34m"
# define YELLOW "\e[0;33m"
# define GREEN "\e[0;32m"
# define RED "\e[0;31m"
# define GREY "\e[0;30m"
# define ENDC "\e[0m"

# include <string>
# include <iostream>

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