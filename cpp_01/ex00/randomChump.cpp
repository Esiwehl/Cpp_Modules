#include "Zombie.hpp"
#include <string>

// void randomChump(std::string name){
//     Zombie* rChump = newZombie(name);
//     rChump->announce();
//     delete rChump;
// }

void randomChump(std::string name){
    Zombie rChump(name);
    rChump.announce();
}