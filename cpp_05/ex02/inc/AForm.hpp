#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>

# include "Bureaucrat.hpp"

class Form {
	private:
		const std::string _name;
		const int _signGrade;
		const int _execGrade;
		bool _isSigned;

	protected:
		virtual void beExecuted() const = 0;

	public:
		Form();
		Form(const std::string& name, int signGrade, int execGrade);
		Form(const Form& other);
		virtual ~Form();

		Form& operator=(const Form& other) = delete;

		int getSignGrade() const;
		int getExecGrade() const;
		bool getSignature() const;
		const std::string getName() const;

		void beSigned(Bureaucrat& b);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const noexcept override {
					return "Grade too high!";
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const noexcept override {
					return "Grade too low!";
				}
		};

};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif