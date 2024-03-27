#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Lovely"), _grade(75) {
	std::cout << "Default bureaucrat constructor called" << std::endl;
	if (_grade < 1) throw GradeTooHighException();
	if (_grade > 150) throw GradeTooLowException();

}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
	std::cout << "Parameterized bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
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

// void Bureaucrat::setName(std::string& name) {
// 	_name = name;
// }

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

// Non-method functions
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b){
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (os);
}
