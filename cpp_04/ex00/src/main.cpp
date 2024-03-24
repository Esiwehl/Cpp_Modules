#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "\n\t[ CONSTRUCTORS CALLS ]\n" << std::endl;
	const Animal* genericAnimal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

    std::cout << "\n---------------------------------------\n" << std::endl;

	std::cout << dog->getType() << ": ";
	dog->makeSound();

	std::cout << cat->getType() << ": ";
	cat->makeSound();

	std::cout << genericAnimal->getType() << ": ";
	genericAnimal->makeSound();

    std::cout << "\n\t[ DESTRUCTOR CALLS ]\n" << std::endl;

    delete genericAnimal;
	delete dog;
	delete cat;

    std::cout << "\n---------------------------------------\n" << std::endl;

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
    const WrongCat* wrongCat2 = new WrongCat();

    std::cout << "\n---------------------------------------\n" << std::endl;

	std::cout << wrongCat->getType() << ": ";
	wrongCat->makeSound();

    std::cout << "\n\t[What it should've been ]\n" << std::endl;
    std::cout << wrongCat->getType() << ": ";
	wrongCat2->makeSound();
    std::cout << std::endl;

	std::cout << wrongAnimal->getType() << ": ";
	wrongAnimal->makeSound();

    std::cout << "\n\t[ DESTRUCTOR CALLS ]\n" << std::endl;
	delete wrongAnimal;
	delete wrongCat;
    delete wrongCat2;

	return 0;
}
