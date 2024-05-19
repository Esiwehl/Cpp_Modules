#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


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

void ex02_shrub() {
	Bureaucrat Jen("jen", 148);
	Bureaucrat Jon("jon", 75);
	
	ShrubberyCreationForm shrub("Outside");
	std::cout << "\n---------------------------------------------\n" <<
		shrub << "---------------------------------------------\n" << 
	std::endl;
	try {
		// Jon.signForm(shrub);
		Jen.signForm(shrub);
	} catch (std::exception &e) {
		std::cout << "Error :" << e.what() << std::endl;
	}
	Jon.executeForm(shrub);

	std::cout << "\n---------------------------------------------\n" <<
	std::endl;
	std::cout << "Jen is not a Karen, Jen grinds. Be like Jen.\n";
	std::cout << "\n---------------------------------------------\n" <<
	std::endl;

	for (; Jen.getGrade() > shrub.getExecGrade(); Jen.incrementGrade());
	try {
		// Jon.signForm(shrub);
		Jen.signForm(shrub);
	} catch (std::exception &e) {
		std::cout << "Error :" << e.what() << std::endl;
	}
	Jon.executeForm(shrub);
	
	// Jen.executeForm(shrub);
}

void ex02_rob() {
	Bureaucrat Gary("Gary", 1);
	Bureaucrat SpongeBob("Spongebob", 50);

	RobotomyRequestForm octo("Octo");
	std::cout << "\n---------------------------------------------\n" <<
		octo << "---------------------------------------------\n" << 
	std::endl;
	try {
		Gary.signForm(octo);
		// SpongeBob.signForm(octo);
	} catch (std::exception &e) {
		std::cout << "Error :" << e.what() << std::endl;
	}
	try {
		SpongeBob.executeForm(octo);
	} catch (std::exception &e) {
		std::cout << "Sadly " << e.what() << std::endl;
	}
	
	std::cout << "So once more he returned to Gary to ask him.\n";
	
	Gary.executeForm(octo);

	std::cout << "Spongebob, would not take this, he needed to be able to execute it himself.\n";
	std::cout << "So he trained ";
	for (;SpongeBob.getGrade() > octo.getExecGrade(); SpongeBob.incrementGrade()) {
		std::cout << "and trained, ";
	}
	std::cout << "\nUntil he was strong enough to execute the **** form.\n";
	SpongeBob.executeForm(octo);
	SpongeBob.executeForm(octo);
}

void ex02_pres() {
	Bureaucrat president("President Zaphod", 1);
    
    // Create the PresidentialPardonForm
    PresidentialPardonForm pardon("Ford Prefect");
    
    // Display initial state
    std::cout << president << std::endl;
    std::cout << pardon << std::endl;

    // Attempt to sign the form
    try {
        president.signForm(pardon);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Display form state after signing attempt
    std::cout << pardon << std::endl;

    // Attempt to execute the form
    try {
        president.executeForm(pardon);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void ex03() {
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy", "Bender");
	rrf = someRandomIntern.makeForm("RobotomyRequest", "Bender");
	delete (rrf);
}

int main() {
	ex03();
	return 0;
}
