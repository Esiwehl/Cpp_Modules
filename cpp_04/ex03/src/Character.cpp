#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

Character::Character(std::string name) : name(name) {
    for (int idx = 0; idx < 4; ++idx) {
        inventory[idx] = nullptr;
    }
}

Character::Character(const Character& other) : name(other.name) {
    for (int idx = 0; idx < 4; ++idx) {
        if (other.inventory[idx]) {
            inventory[idx] = other.inventory[idx]->clone();
        } else {
            inventory[idx] = nullptr;
        }
    }
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        name = other.name;
        for (int idx = 0; idx < 4; ++idx) {
            delete inventory[idx]; // Free any existing materia
            if (other.inventory[idx]) {
                inventory[idx] = other.inventory[idx]->clone();
            } else {
                inventory[idx] = nullptr;
            }
        }
    }
    return *this;
}

Character::~Character() {
    for (int idx = 0; idx < 4; ++idx) {
        delete inventory[idx];
    }
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    for (int idx = 0; idx < 4; ++idx) {
        if (inventory[idx] == nullptr) {
            inventory[idx] = m;
            break;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4) {
        inventory[idx] = nullptr; // doesn't delete
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && inventory[idx] != nullptr) {
        inventory[idx]->use(target);
		std::cout << "here\n";
    }
}
