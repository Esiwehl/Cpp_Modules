#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie {
    private:
        std::string _name;

    public:
    Zombie( void );
    Zombie( std::string name );
    ~Zombie();

    void setName(std::string name);
    void announce( void );
    void getName();
};

Zombie* zombieHorde( int N, std::string name );

#endif