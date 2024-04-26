#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Form;

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;
	
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& other);
		
		void setGrade(int grade);

		int getGrade() const;
		const std::string& getName() const;

		void incrementGrade();
		void decrementGrade();

		void signForm(Form& f);

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const noexcept override;
		};

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const noexcept override;
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif