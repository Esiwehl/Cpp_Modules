#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

void	testMateriaSource(void)
{
	std::cout << std::endl <<  "-------------------------------" << std::endl
		<< "\tMATERIA SOURCE TEST" << std::endl
		<<  "-------------------------------" << std::endl;
	std::cout << std::endl << "-- MATERIA SOURCE CREATION" << std::endl;
	MateriaSource * source = new MateriaSource();
	source->displayKnownMateria();

	std::cout << std::endl << "-- MATERIA SOURCE LEARNING RECIPES" << std::endl;
	source->learnMateria(nullptr);
	source->learnMateria(new Cure());
	source->learnMateria(new Ice());
	source->displayKnownMateria();

	std::cout << std::endl << "-- MATERIA SOURCE DEEP COPY" << std::endl;
	MateriaSource * copySource = new MateriaSource(*source);
	std::cout << "Original ";
	source->displayKnownMateria();
	std::cout << "Copy ";
	copySource->displayKnownMateria();
	std::cout << "Original Materia Source learns another recipe:" << std::endl;
	source->learnMateria(new Cure());
	std::cout << "Original ";
	source->displayKnownMateria();
	std::cout << "Copy ";
	copySource->displayKnownMateria();
	std::cout << "Deleting Copy Materia Source:" << std::endl;
	delete copySource;

	std::cout << std::endl << "-- MATERIA SOURCE LEARNING TOO MANY RECIPES" << std::endl;
	source->displayKnownMateria();
	source->learnMateria(new Ice());
	source->learnMateria(new Cure());
	source->displayKnownMateria();

	std::cout << std::endl << "-- MATERIA SOURCE CREATING MATERIA FROM RECIPES" << std::endl;
	AMateria *m1 = nullptr;
	AMateria *m2 = nullptr;
	AMateria *m3 = nullptr;
	
	m1 = source->createMateria("ice");
	if (m1 == nullptr)
		std::cout << "Materia was not created." << std::endl;
	else
		std::cout << "Created materia is " << m1->getType() << std::endl;
	m2 = source->createMateria("cure");
	if (m2 == nullptr)
		std::cout << "Materia was not created." << std::endl;
	else
		std::cout << "Created materia is " << m2->getType() << std::endl;
	m3 = source->createMateria("rock");
	if (m3 == nullptr)
		std::cout << "Materia was not created." << std::endl;
	else
		std::cout << "Created materia is " << m2->getType() << std::endl;
	if (m1 != nullptr)
		delete m1;
	if (m2 != nullptr)
		delete m2;
	if (m2 != nullptr)
		delete m3;

	std::cout << std::endl << "-- MATERIA SOURCE DELETION" << std::endl;
	delete source;
}

void	testCharacters(void)
{
	std::cout << std::endl <<  "-------------------------------" << std::endl
		<< "\tCHARACTER TEST" << std::endl
		<<  "-------------------------------" << std::endl;
	std::cout << std::endl << "-- MATERIA CREATION" << std::endl;
	AMateria *m1 = new Cure();
	AMateria *m2 = new Cure();
	AMateria *m3 = new Cure();
	AMateria *m4 = new Ice();
	AMateria *m5 = new Ice();
	AMateria *m6 = new Ice();

	std::cout << std::endl << "-- CHARACTER CREATION" << std::endl;
	Character *jane = new Character("Jane");
	jane->displayInventory();

	std::cout << std::endl << "-- CHARACTER EQUIPPING ITEMS" << std::endl;
	jane->equip(nullptr);
	jane->equip(m1);
	jane->equip(m2);
	jane->displayInventory();

	std::cout << std::endl << "-- CHARACTER DEEP COPY" << std::endl;
	Character *janeCopy = new Character(*jane);
	std::cout << "Changing copy's name from \"" << janeCopy->getName()
		<< "\" to \"Copy\"." << std::endl;
	janeCopy->setName("Copy");
	jane->displayInventory();
	janeCopy->displayInventory();
	jane->equip(m3);
	jane->displayInventory();
	janeCopy->displayInventory();
	std::cout << "Deleting copy character:" << std::endl;
	delete janeCopy;

	std::cout << std::endl << "-- CHARACTER EQUIPPING TOO MANY ITEMS" << std::endl;
	jane->displayInventory();
	jane->equip(m4);
	jane->equip(m5);
	jane->equip(m6);
	jane->displayInventory();

	std::cout << std::endl << "-- CHARACTER UNEQUIPPING ITEMS" << std::endl;
	jane->unequip(-1);
	jane->unequip(10000);
	jane->unequip(4);
	jane->unequip(2);
	jane->displayInventory();
	jane->equip(m5);
	jane->displayInventory();
	jane->unequip(1);
	jane->unequip(2);
	jane->displayInventory();
	jane->unequip(2);

	std::cout << std::endl << "-- CHARACTER UNEQUIPPING ITEM DOES NOT DELETE IT" << std::endl;
	std::cout << "- Creating a tmp materia of type cure:" << std::endl;
	AMateria * tmp = new Cure();
	std::cout << "- Equipping the tmp materia:" << std::endl;
	jane->equip(tmp);
	std::cout << "- Unequipping the tmp materia:" << std::endl;
	jane->unequip(1);
	std::cout << "- Deleting the tmp materia:" << std::endl;
	delete tmp;

	std::cout << std::endl << "-- CHARACTER DELETION" << std::endl;
	delete jane;

	std::cout << std::endl << "-- CLEANING UP UNEQUIPPED MATERIA" << std::endl;
	delete m2;
	delete m3;
	delete m5;
	delete m6;
}

int	main(void)
{
	testMateriaSource();
	// testCharacters();
	return (0);
}