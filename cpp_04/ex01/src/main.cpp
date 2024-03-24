#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

void deepCopyProve() {
	Dog originalDog;
    Dog copyDog = originalDog;
    Cat originalCat;
    Cat copyCat = originalCat;
	
	std::cout << "Original Dog's first idea: " << originalDog.getBrain().getIdea(0) << std::endl;
    std::cout << "Copy Dog's first idea: " << copyDog.getBrain().getIdea(0) << std::endl;
    std::cout << "Original Cat's first idea: " << originalCat.getBrain().getIdea(0) << std::endl;
    std::cout << "Copy Cat's first idea: " << copyCat.getBrain().getIdea(0) << std::endl;
	
	std::cout << "\n-----------------------------------------\n" << std::endl;

	originalDog.getBrain().setIdea(0, "Original Dog Idea");
	copyDog.getBrain().setIdea(0, "Copy Dog Idea");
    originalCat.getBrain().setIdea(0, "Original Cat Idea");
    copyCat.getBrain().setIdea(0, "Copy Cat Idea");

	std::cout << "\n-----------------------------------------\n" << std::endl;

    std::cout << "Original Dog's first idea: " << originalDog.getBrain().getIdea(0) << std::endl;
    std::cout << "Copy Dog's first idea: " << copyDog.getBrain().getIdea(0) << std::endl;
    std::cout << "Original Cat's first idea: " << originalCat.getBrain().getIdea(0) << std::endl;
    std::cout << "Copy Cat's first idea: " << copyCat.getBrain().getIdea(0) << std::endl;

	std::cout << "\n\t[DESTRUCTORS]\n" << std::endl;

}

void polymorphismProve(){
	const int numAnimals = 10;
    Animal* animals[numAnimals];

    for (int i = 0; i < numAnimals; ++i) {
        if (i % 2 == 0) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }

    for (int i = 0; i < numAnimals; ++i) {
        animals[i]->makeSound();
    }

    Dog originalDog;
    Dog copyDog(originalDog);

    Cat originalCat;
    Cat copyCat = originalCat;

    for (int i = 0; i < numAnimals; ++i) {
        delete animals[i];
    }
}

int main() {
	deepCopyProve();
	// polymorphismProve();
	return 0;
}
