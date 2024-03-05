#include "Zombie.hpp"
#include <string>

Zombie* newZombie(std::string name){
    Zombie* newZ = new Zombie(name);
    return newZ;
}