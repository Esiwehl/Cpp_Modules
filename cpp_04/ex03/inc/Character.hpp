#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
private:
    std::string name;
    AMateria* inventory[4];

public:
    Character(std::string name);
    Character(const Character& other);
    Character& operator=(const Character& other);
    virtual ~Character();

    virtual std::string const & getName() const override;
    virtual void equip(AMateria* m) override;
    virtual void unequip(int idx) override;
    virtual void use(int idx, ICharacter& target) override;
};

#endif
