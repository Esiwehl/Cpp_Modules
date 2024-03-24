#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
private:
    std::string _name;
    static int const _invSize = 4;
    AMateria* _inventory[_invSize];

    void _initEmptyInv();
    void _deleteInv();

public:
    Character();
    Character(std::string name);
    Character(const Character& other);
    Character& operator=(const Character& other);
    virtual ~Character();

    void setName(std::string name);
    std::string const & getName() const override;
    virtual void equip(AMateria* m) override;
    virtual void unequip(int idx) override;
    virtual void use(int idx, ICharacter& target) override;
    
    void displayInventory() const;
};

#endif
