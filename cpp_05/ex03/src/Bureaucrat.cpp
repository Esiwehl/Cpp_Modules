#include "Bureaucrat.hpp"
# include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Lovely"), _grade(75) {
	std::cout << "Default bureaucrat constructor called" << std::endl;
	if (_grade < 1) throw GradeTooHighException();
	if (_grade > 150) throw GradeTooLowException();

}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
	std::cout << "Parameterized bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name + "_copy"), _grade(other._grade) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		_grade = other.getGrade();
	}
	return (*this);
}

void Bureaucrat::setGrade(int grade) {
	_grade = grade;
}

const std::string& Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	if (_grade <= 1) throw GradeTooHighException();
	--this->_grade;
}

void Bureaucrat::decrementGrade() {
	if (_grade >= 150) throw GradeTooLowException();
	++this->_grade;
}

void Bureaucrat::signForm(AForm& f) {
	try {
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << _name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form) {
    try {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << _name << " could not execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

//Exceptions
const char* Bureaucrat::GradeTooLowException::what() const noexcept {
	return "Grade too low! Keep grinding";
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return "Grade too high! You've plateaud here, time for another job.";
}

// Non-member functions
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b){
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (os);
}
