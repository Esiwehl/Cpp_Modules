#include <iostream>
#include "ClapTrap.hpp"

int main(){
    ClapTrap ct("CT_01");
    ClapTrap ct2("CT_02");

    ct.attack("you");

    while (ct.getEnergyPoints() != 5 && ct2.getEnergyPoints() != 0){
        ct2.attack(ct.getName());
        ct.takeDamage(ct2.getAttackDamage());
        ct.attack(ct2.getName());
        ct2.takeDamage(ct.getAttackDamage());
    }

    std::cout << "Oh no, a sudden thunderstrike hits " << ct.getName() << std::endl;
    ct.takeDamage(100);
    std::cout << "Due to AoE damage " <<ct2.getName() << " also takes some damage." << std::endl;
    ct2.takeDamage(8);
    std::cout << ct2.getName() << " just barely managed to escape with " << ct2.getHitPoints() << " hitpoints left\n";

    std::cout << "Time to heal." << std::endl;
    ct2.beRepaired(10);
    std::cout << ct2.getName() << " now has " << ct2.getHitPoints() << " hit points."
        << "and " << ct2.getEnergyPoints() << " energy points.";
}