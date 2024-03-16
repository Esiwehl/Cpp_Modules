#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(){
    DiamondTrap dt("DT_04");

    dt.whoAmI();
    dt.attack("yer mum");
    dt.takeDamage(30);
    dt.beRepaired(20);

    std::cout << "DiamondTrap ends its journey with " << dt.getHitPoints() << " hit points left.\n";

    return 0;
}
