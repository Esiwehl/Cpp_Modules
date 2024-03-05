# include "Zombie.hpp"
#include <string>

int main (void)
{
    int N = 5;
    Zombie *zH = zombieHorde(N, "Jameos");
    
    for (int idx = 0; idx < N; idx++)
    {
        zH[idx].announce();
        delete &zH[idx];
    }

    return 0;
}