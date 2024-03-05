#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){
    if (N < 0)
        return NULL;
    Zombie *zombieHorde = new Zombie[N];
    for (int idx = 0; idx < N; idx++){
        zombieHorde[idx].setName(name);
    }
    return (zombieHorde);
}