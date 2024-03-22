#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal* genericAnimal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << dog->getType() << ": ";
	dog->makeSound();

	std::cout << cat->getType() << ": ";
	cat->makeSound();

	std::cout << genericAnimal->getType() << ": ";
	genericAnimal->makeSound();

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << ": ";
	wrongCat->makeSound();

	std::cout << wrongAnimal->getType() << ": ";
	wrongAnimal->makeSound();

	delete genericAnimal;
	delete dog;
	delete cat;
	delete wrongAnimal;
	delete wrongCat;

	return 0;
}
