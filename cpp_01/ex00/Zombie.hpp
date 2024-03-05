#include <string>

class Zombie {
    private:
        std::string _name;
        void setName(std::string name); //?

    public:
    Zombie( void );
    Zombie( std::string name );
    ~Zombie();

    void announce( void );
    void getName();
};

Zombie* newZombie(std::string name);
void randomChump( std::string name );