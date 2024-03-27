#include "Bureaucrat.hpp"
#include "Form.hpp"

void ex00(){
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
}

void ex01_1(){
	Form randomPieceOfPaper("randomPoP", 10, 10);
	Form specialPieceOfPaper("specialPoP", 135, 145);

	Bureaucrat averageJoe("averageJoe", 70);
	Bureaucrat princessOfMontenaro("princess", 150);

	Form cpRandomPoP(randomPieceOfPaper);
	Form cpSpecialPoP(specialPieceOfPaper);

	try {
		princessOfMontenaro.signForm(randomPieceOfPaper);
		averageJoe.signForm(cpRandomPoP);
		princessOfMontenaro.signForm(specialPieceOfPaper);
		averageJoe.signForm(specialPieceOfPaper);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void ex01_2() {
	// Form PieceOfPaper("randomPoP", 10, 10);
	Form PieceOfPaper("specialPoP", 135, 145);

	Bureaucrat averageJoe("averageJoe", 70);
	Bureaucrat princessOfMontenaro("princess", 150);

	std::cout << "\t\t[PRINITNG BUREAUCRAT STATS]\n" 
		<< averageJoe << std::endl
		<< princessOfMontenaro << std::endl;

	Form cpPoP(PieceOfPaper);
	// Form cpSpecialPoP(specialPieceOfPaper);

	std::cout << "\t\t[PRE SIGNATURE SKIZZLE]\n"
		<< PieceOfPaper << std::endl
		<< cpPoP << std::endl;

	try {
		PieceOfPaper.beSigned(princessOfMontenaro);
		cpPoP.beSigned(averageJoe);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\t\t[POST SIGNATURE SKIZZLE]\n"
		<< PieceOfPaper << std::endl
		<< cpPoP << std::endl;
}

int main() {
	// ex00();
	// ex01_1();
	ex01_2();

	return 0;
}
