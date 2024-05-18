#include "RobotomyRequestForm.hpp"
#include <iostream> 
#include <cstdlib>
#include <ctime>

#define ROB_SIGN_GRADE 72
#define ROB_EXEC_GRADE 45

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", ROB_SIGN_GRADE, ROB_EXEC_GRADE), _target("default") {
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm " + target, ROB_SIGN_GRADE, ROB_EXEC_GRADE), _target(target) {
	std::cout << "RobotomyRequestForm parameterized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target) {
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::beExecuted() const {
    srand(time(NULL));
	std::cout << "Makes some drilling noised.\n";
    if (rand() % 2 == 0)
        std::cout << _target << " has been succesfully robotomized!\n";
    else
        std::cout << _target + "'s robotomy has failed...\n";
}