#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

Character::Character() : _name("unknown") {
    std::cout << "Unknown character default constructor called\n";
    this->_initEmptyInv();
}

Character::Character(std::string name) : _name(name) {
    std::cout << "Character default constructor called\n";
    this->_initEmptyInv();
}

Character::Character(const Character& other) : _name(other._name) {
    std::cout << "Character copy constructor called\n";
    for (int idx = 0; idx < _invSize; ++idx) {
        if (other._inventory[idx]) {
            _inventory[idx] = other._inventory[idx]->clone();
        } else {
            _inventory[idx] = nullptr;
        }
    }
}

Character& Character::operator=(const Character& other) {
    std::cout << "Character assignment operator overload called\n";
    if (this != &other) {
        _name = other._name;
        for (int idx = 0; idx < _invSize; ++idx) {
            delete this->_inventory[idx];
            if (other._inventory[idx]) {
                this->_inventory[idx] = other._inventory[idx]->clone();
            } else {
                this->_inventory[idx] = nullptr;
            }
        }
    }
    return *this;
}

Character::~Character() {
    std::cout << "Character destructor called\n";
    this->_deleteInv();
}

void Character::setName(std::string name) {
    this->_name = name;
}

std::string const & Character::getName() const {
    return this->_name;
}

void Character::equip(AMateria *m) {
    if (m == nullptr){
        std::cout << this->_name << ": Can't equip something that doesn't exist!"
            << std::endl;
        return ;
    }
    for (int idx = 0; idx < _invSize; ++idx) {
        if (_inventory[idx] == nullptr) {
            _inventory[idx] = m;
            std::cout << this->_name
				<< " equipped " << m->getType()
				<< " materia to inventory index " << idx << "." << std::endl;
            return;
        }
    }
    std::cout << this->_name << ": Is completely equipped!" << std::endl;
}

void	Character::unequip(int index)
{
	if (index < 0 || index >= this->_invSize)
	{
		std::cout << this->_name
			<< ": I can't unequip anything from inventory index " << index
			<< ". It's not a valid index!" << std::endl;
		return ;
	}
	if (this->_inventory[index] == NULL)
	{
		std::cout << this->_name
			<< ": I don't have anything at index " << index << " to unequip!"
			<< std::endl;
		return ;
	}
	std::cout << this->_name
		<< " unequipped " << this->_inventory[index]->getType()
		<< " materia from inventory index " << index << "." << std::endl;
	this->_inventory[index] = NULL;	
	return ;
}

void	Character::use(int index, ICharacter & target)
{
	if (index < 0 || index >= this->_invSize)
	{
		std::cout << this->_name << ": Can't use item at inventory index " << index
			<< ". It's not a valid index!" << std::endl; 
		return ;
	}
	if (this->_inventory[index] != NULL)
	{
		std::cout << this->_name << ": ";
		this->_inventory[index]->use(target);
	}
	else
		std::cout << this->_name
			<< ": Oops, I don't have an item in my inventory at index "
			<< index << "!" << std::endl;
	return ;
}

void	Character::displayInventory() const
{
	std::cout << this->_name << "'s inventory contains:" << std::endl;
	for (int idx = 0; idx < this->_invSize; idx++)
	{
		std::cout << "\t[" << idx << "] ";
		if (this->_inventory[idx] == NULL)
			std::cout << "Empty slot.";
		else
			std::cout << this->_inventory[idx]->getType() << " materia.";
		std::cout << std::endl;
	}
	return ;
}

void Character::_initEmptyInv() {
	for (int idx = 0; idx < this->_invSize; idx++)
		this->_inventory[idx] = nullptr;
	return ;
}

void Character::_deleteInv() {
    for (int idx = 0; idx < _invSize; ++idx) {
        delete _inventory[idx];
    }
}
