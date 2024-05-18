#include "AForm.hpp"

#include "PresidentialPardonForm.hpp"
#include <iostream> 
#include <cstdlib>
#include <ctime>

#define PRES_SIGN_GRADE 25
#define PRES_EXEC_GRADE 5

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon", PRES_SIGN_GRADE, PRES_EXEC_GRADE), _target("default") {
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm " + target, PRES_SIGN_GRADE, PRES_EXEC_GRADE), _target(target) {
	std::cout << "PresidentialPardonForm parameterized constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target) {
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::beExecuted() const {
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}