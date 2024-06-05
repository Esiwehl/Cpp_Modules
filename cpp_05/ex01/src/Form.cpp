#include "Form.hpp"

Form::Form() : _name("Default"), _signGrade(150), _execGrade(150), _isSigned(false) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string &name, int gradeRequiredToSign, int gradeRequiredToExecute) : _name(name), _signGrade(gradeRequiredToSign), _execGrade(gradeRequiredToExecute), _isSigned(false) {
	std::cout << "Form parameterized constructor called" << std::endl;
	if (_signGrade < 1 || _execGrade < 1) throw GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150) throw GradeTooLowException();
}

Form::Form(const Form& other) : _name(other._name + "_copy"), _signGrade(other._signGrade), _execGrade(other._execGrade), _isSigned(other._isSigned) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}
// Form& Form::operator=(const Form& other) = delete;

int Form::getSignGrade() const {
	return _signGrade;
}
int Form::getExecGrade() const {
	return _execGrade;
}

bool Form::getSignature() const {
	return _isSigned;
}

const std::string Form::getName() const {
	return _name;
}

void Form::beSigned(Bureaucrat& b) {
	if (b.getGrade() <= _signGrade) {
		_isSigned = true;
	} else {
		throw GradeTooLowException();
	}
}

//Exceptions
const char* Form::GradeTooLowException::what() const noexcept {
	return "Grade too low!";
}

const char* Form::GradeTooHighException::what() const noexcept {
	return "Grade too high!";
}



// Non-member function
std::ostream& operator<<(std::ostream& os, const Form& f) {
	os << f.getName() << "\n\t"
		<< "status: " <<  (f.getSignature() ? "Signed" : "Unsigned")
		<< "\n\tGrade required to sign: " << f.getSignGrade() 
		<< "\n\tGrade required to exec: " << f.getExecGrade()
		<< std::endl;
	return os;
}
