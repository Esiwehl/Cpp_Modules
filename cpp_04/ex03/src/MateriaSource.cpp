#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int idx = 0; idx < 4; ++idx) {
        slots[idx] = nullptr;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int idx = 0; idx < 4; ++idx) {
        if (other.slots[idx]) {
            slots[idx] = other.slots[idx]->clone();
        } else {
            slots[idx] = nullptr;
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        for (int idx = 0; idx < 4; ++idx) {
            delete slots[idx];
            if (other.slots[idx]) {
                slots[idx] = other.slots[idx]->clone();
            } else {
                slots[idx] = nullptr;
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int idx = 0; idx < 4; ++idx) {
        delete slots[idx];
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int idx = 0; idx < 4 && slots[idx] != nullptr; ++idx) {
        if (slots[idx] == nullptr) {
            slots[idx] = m;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int idx = 0; idx < 4; ++idx) {
        if (slots[idx] != nullptr && slots[idx]->getType() == type) {
            return slots[idx]->clone();
        }
    }
    return nullptr;
}
