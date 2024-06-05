#include "Base.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

int main() {
	srand(static_cast<unsigned int>(time(nullptr)));

	for (int i = 0; i < 10; ++i) {
		Base* ptr = generate();
		std::cout << "Generated class type identified by pointer: ";
		identify(ptr);
		std::cout << "Generated class type identified by reference: ";
		identify(*ptr);
		delete ptr;
	}
	return 0;
}