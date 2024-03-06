#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde( int N, std::string name ){
    Zombie *zombieHorde;
    if (N < 0)
        return nullptr;

    try{
        zombieHorde = new Zombie[N];
    } catch (const std::bad_alloc& e){
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    }
    for (int idx = 0; idx < N; idx++){
        zombieHorde[idx].setName(name);
    }
    return (zombieHorde);
}