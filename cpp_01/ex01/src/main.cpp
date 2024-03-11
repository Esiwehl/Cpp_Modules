# include "Zombie.hpp"
#include <string>

int main (void)
{
    int N = 10;
    Zombie *zH = zombieHorde(N, "Jameos");
    
    if (!zH)
        return 1;
    for (int idx = 0; idx < N; idx++){
        zH[idx].announce();
    }

    delete[] zH;
    return 0;
}