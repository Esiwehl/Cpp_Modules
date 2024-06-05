#include <cstdlib>
#include <iostream>

#include "Base.hpp"
#include "ABC.hpp"

Base::~Base() {
	//Purposefully empty.
}

Base* generate() {
	switch (rand() % 3) {
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (nullptr);
	}
}

void identify(Base* p) {
	if (p == NULL) return;
	if (dynamic_cast<A*>(p)) std::cout << "A\n";
	else if (dynamic_cast<B*>(p)) std::cout << "B\n";
	else if (dynamic_cast<C*>(p)) std::cout << "C\n";
}

void identify(Base& p) {
	try {
		(void) dynamic_cast<A&>(p);
		std::cout << "A\n";
	} catch (std::bad_cast&) {
		try {
		(void) dynamic_cast<B&>(p);
		std::cout << "B\n";
		} catch (std::bad_cast&) {
			try {
			(void) dynamic_cast<C&>(p);
			std::cout << "C\n";
			} catch (std::bad_cast&) {
			std::cerr << "Unable to identify\n";
			}
		}
	}
}