#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main() {

	Point const a(2.2f, 3.1f);
	Point const b(4.7f, 2.0f);
	Point const c(3.1f, 1.0f);

	Point const yesP(4.0f, 2.0f);
	Point const noP(1.5f, 2.0f);

	bool result = bsp(a, b, c, noP);
	std::cout << noP << ((result) ? "Is" : "Is not") << " in the triangle" << std::endl;

	return 0;
}