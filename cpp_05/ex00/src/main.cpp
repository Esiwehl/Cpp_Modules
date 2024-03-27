#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat bobMarley("Bob Marley", 2);
		std::cout << bobMarley << std::endl;
		bobMarley.incrementGrade();
		std::cout << bobMarley << std::endl;
		bobMarley.incrementGrade(); // Should throw an exception
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat amy("Amy Winehouse", 149);
		std::cout << amy << std::endl;
		amy.decrementGrade();
		std::cout << amy << std::endl;
		amy.decrementGrade(); // Should throw an exception
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat jeff("Jeff", -4);
		std::cout << jeff << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}