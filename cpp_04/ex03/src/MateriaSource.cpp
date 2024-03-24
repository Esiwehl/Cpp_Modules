#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
    std::cout << "MateriaSource default constructor called" << std::endl;
    this->_initEmptySlots();
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    std::cout << "MateriaSource copy constructor called" << std::endl;
    for (int idx = 0; idx < _maxMateria; ++idx) {
        if (other._slots[idx]) {
            _slots[idx] = other._slots[idx]->clone();
        } else {
            _slots[idx] = nullptr;
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    std::cout << "MateriaSource assignment operator overload called"
        << std::endl;
    if (this != &other) {
        for (int idx = 0; idx < _maxMateria; ++idx) {
            delete _slots[idx];
            if (other._slots[idx]) {
                _slots[idx] = other._slots[idx]->clone();
            } else {
                _slots[idx] = nullptr;
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource destructor called";
    this->_deleteSlots();
}

void MateriaSource::learnMateria(AMateria * materia)
{
	if (!materia)
	{
		std::cout << "What's there to learn..?" << std::endl;
		return ;
	}
	for (int i = 0; i < this->_maxMateria; i++)
	{
		if (this->_slots[i] == nullptr)
		{
			this->_slots[i] = materia;
			std::cout << "MateriaSource learned the " << materia->getType()
				<< " materia recipe." << std::endl;
			return ;
		}
	}
	std::cout << "I used all my braincells." << std::endl;
	delete materia;
	return ;
}

AMateria *	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < this->_maxMateria; i++)
	{
		if (this->_slots[i] && this->_slots[i]->getType() == type)
		{
			std::cout << "MateriaSource creating " << type
				<< " materia." << std::endl;
			return (this->_slots[i]->clone());
		}
	}
	std::cout << "MateriaSource does not know the type \""
		<< type << "\"." << std::endl;
	return (nullptr);
}

void MateriaSource::_initEmptySlots()
{
	for (int idx = 0; idx < this->_maxMateria; idx++)
		this->_slots[idx] = nullptr;
	return ;
}

void MateriaSource::_deleteSlots(void)
{
	for (int idx = 0; idx < this->_maxMateria; idx++)
	{
		if (this->_slots[idx] != nullptr)
		{
			delete this->_slots[idx];
			this->_slots[idx] = nullptr;
		}
	}
	return ;
}

void MateriaSource::displayKnownMateria() {
    std::cout << "MateriaSource knows the following recipes:" << std::endl;
	for (int idx = 0; idx < this->_maxMateria; idx++)
	{
		std::cout << "\t[" << idx << "] ";
		if (this->_slots[idx] == nullptr)
			std::cout << "Empty slot.";
		else
			std::cout << this->_slots[idx]->getType() << " materia.";
		std::cout << std::endl;
	}
	return ;
}