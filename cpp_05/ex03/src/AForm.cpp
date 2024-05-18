#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signGrade(150), _execGrade(150), _isSigned(false) {
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, int gradeRequiredToSign, int gradeRequiredToExecute) : _name(name), _signGrade(gradeRequiredToSign), _execGrade(gradeRequiredToExecute), _isSigned(false) {
	std::cout << "AForm parameterized constructor called" << std::endl;
	if (_signGrade < 1 || _execGrade < 1) throw GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150) throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other._name + "_copy"), _signGrade(other._signGrade), _execGrade(other._execGrade), _isSigned(other._isSigned) {
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm() {
	std::cout << "AForm destructor called" << std::endl;
}

// AForm& AForm::operator=(const AForm& other) = delete;

int AForm::getSignGrade() const {
	return _signGrade;
}
int AForm::getExecGrade() const {
	return _execGrade;
}

bool AForm::getSignature() const {
	return _isSigned;
}

const std::string AForm::getName() const {
	return _name;
}

void AForm::beSigned(Bureaucrat& b) {
	if (_isSigned == true){
		throw FormAlreadySignedException();
	} else if (b.getGrade() <= _signGrade) {
		_isSigned = true;
	} else {
		throw GradeTooLowException();
	}
}

void AForm::checkFormExecution(const Bureaucrat &executor) const {
	if (_isSigned == false) throw FormNotSignedException();
	if (executor.getGrade() > _execGrade) throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const& executor) const {
	checkFormExecution(executor);
	beExecuted();
}

//Exceptions
const char* AForm::FormNotSignedException::what() const noexcept {
	return "Form has not been signed!";
}

const char* AForm::FormAlreadySignedException::what() const noexcept {
	return "Form is already signed!";
}

const char* AForm::GradeTooHighException::what() const noexcept {
	return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const noexcept {
	return "Grade too low!";
}

// Non-member function
std::ostream& operator<<(std::ostream& os, const AForm& f) {
	os << f.getName() << "\n\t"
		<< "status: " <<  (f.getSignature() ? "Signed" : "Unsigned")
		<< "\n\tGrade required to sign: " << f.getSignGrade() 
		<< "\n\tGrade required to exec: " << f.getExecGrade()
		<< std::endl;
	return os;
}
