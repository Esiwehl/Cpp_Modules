#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>

# include "Bureaucrat.hpp"

class AForm {
	protected:
		const std::string _name;
		const int _signGrade;
		const int _execGrade;
		bool _isSigned;

		void checkFormExecution(const Bureaucrat &executor) const;

	public:
		AForm();
		AForm(const std::string& name, int signGrade, int execGrade);
		AForm(const AForm& other);
		virtual ~AForm();

		AForm& operator=(const AForm& other) = delete;

		int getSignGrade() const;
		int getExecGrade() const;
		bool getSignature() const;
		const std::string getName() const;

		void beSigned(Bureaucrat& b);

		void execute(Bureaucrat const& executor) const;
		virtual void beExecuted() const = 0;

		class FormNotSignedException : public std::exception {
    		public:
				const char* what() const noexcept override;
		};

		class FormAlreadySignedException : public std::exception {
    		public:
        		const char* what() const noexcept override;
    	};

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const noexcept override;
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif