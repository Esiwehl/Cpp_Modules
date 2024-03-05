# include "Zombie.hpp"
#include <string>

int main (void)
{
    Zombie *zack, *cody;

    zack = newZombie("Zack");
    cody = newZombie("Cody");

    zack->announce();
    cody->announce();

    randomChump("Brody");
    randomChump("Zames");

    delete zack;
    delete cody;
    return 0;
}