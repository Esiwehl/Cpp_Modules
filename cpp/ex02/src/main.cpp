#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(){
    ClapTrap ct("CT_01");
    ScavTrap st("ST_02");
    FragTrap ft("FT_03");

    std::cout << "\t\t=== The Adventure Begins ===\n\n";
    std::cout << "\n\t\t--- The Introduction ---\n";
    ct.attack("a menacing shadow");
    st.guardGate();
    ft.highFivesGuys();

    std::cout << "\n\t\t--- The Encounter ---\n";
    st.attack(ct.getName());
    ct.takeDamage(st.getAttackDamage());

    ft.attack(st.getName());
    st.takeDamage(ft.getAttackDamage());

    std::cout << "\n\t\t--- The Recovery ---\n";
    ct.beRepaired(5);
    st.beRepaired(10);
    ft.beRepaired(15);

    std::cout << "\n\t\t--- The Ultimate Challenge ---\n";
    std::cout << "A wild storm appears, causing area of effect damage!\n";
    ct.takeDamage(20);
    st.takeDamage(20);
    ft.takeDamage(20);

    std::cout << "\n\t\t--- The Aftermath ---\n";
    std::cout << ct.getName() << st.getName()<< " and " << ft.getName() <<" despite the odds, stand victorious.\n";
    std::cout << "They celebrate by all flipping eachother of, as taught by " << ft.getName() << ".\n";

    std::cout << "\n\t\t--- The End of The Adventure ---\n";
    return 0;
}