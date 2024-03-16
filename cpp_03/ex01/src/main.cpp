#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#define CYAN "\e[0;36m"
#define PURPLE "\e[0;35m"
#define BLUE "\e[0;34m"
#define YELLOW "\e[0;33m"
#define GREEN "\e[0;32m"
#define RED "\e[0;31m"
#define GREY "\e[0;30m"
#define ENDC "\e[0m"

int main(){
    int idx = 0;
    ClapTrap ct("CT_01");
    ScavTrap ct2("CT_02");

    ct.attack("you");

    std::cout << GREEN << ct.getName() << " now has " << ct.getHitPoints() << " hit points."
        << "and " << ct.getEnergyPoints() << " energy points." << ENDC << std::endl;
    std::cout << GREEN << ct2.getName() << " now has " << ct2.getHitPoints() << " hit points."
        << "and " << ct2.getEnergyPoints() << " energy points." << ENDC << std::endl;

    while (ct.getHitPoints() >= 0 && ct.getEnergyPoints() != 0){
        idx += 1;
        std::cout << YELLOW << "\t\t\t[ ROUND: " << idx << " ]" << ENDC <<std::endl;
        ct.attack(ct2.getName());
        ct2.takeDamage(ct.getAttackDamage());
        ct2.attack(ct.getName());
        ct.takeDamage(ct2.getAttackDamage());
        std::cout << CYAN << ct.getName() << " has " << ct.getHitPoints() << " left\n" << ENDC << std::endl;
    }

    std::cout << "Oh no, a sudden thunderstrike hits " << ct.getName() << std::endl;
    ct.takeDamage(100);
    std::cout << "Due to AoE damage " <<ct2.getName() << " also takes some damage." << std::endl;
    ct2.takeDamage(8);
    std::cout << ct2.getName() << " just barely managed to escape with " << ct2.getHitPoints() << " hitpoints left\n";

    std::cout << "Time to heal." << std::endl;
    ct2.beRepaired(10);
    std::cout << ct2.getName() << " now has " << ct2.getHitPoints() << " hit points."
        << "and " << ct2.getEnergyPoints() << " energy points.\n";

    ct2.guardGate();
}