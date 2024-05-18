#include "ShrubberyCreationForm.hpp"
#include <fstream>

#define SHRUB_SIGN_GRADE 145
#define SHRUB_EXEC_GRADE 137

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", SHRUB_SIGN_GRADE, SHRUB_EXEC_GRADE), _target("default") {
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm " + target, SHRUB_SIGN_GRADE, SHRUB_EXEC_GRADE), _target(target) {
	std::cout << "ShrubberyCreationForm parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::beExecuted() const {
	std::ofstream outf(_target + "_shrubbery");

	if (!outf) {
        std::cerr << "Failed to open file: " << _target << "_shrubbery" << std::endl;
        return;
    }

 	outf << "       _-_\n";
    outf << "    /~~   ~~\\\n";
    outf << " /~~         ~~\\\n";
    outf << "{               }\n";
    outf << " \\  _-     -_  /\n";
    outf << "   ~  \\\\ //  ~\n";
    outf << "_- -   | | _- _\n";
    outf << "  _ -  | |   -_\n";
    outf << "      // \\\\\n";
	
	outf.close();
}