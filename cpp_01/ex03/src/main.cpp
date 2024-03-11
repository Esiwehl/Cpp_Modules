#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void )
{
    Weapon club = Weapon("crude spiked club");
    
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");

    Weapon clubjim = Weapon("LaserBeam");
    HumanB jim("Jim");
    jim.attack();
    jim.setWeapon(clubjim);
    jim.attack();
    clubjim.setType("Sword");
    
    bob.attack();
    jim.attack();

    return 0;
}