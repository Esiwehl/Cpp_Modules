#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
    const std::string _target;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    virtual ~ShrubberyCreationForm();

    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other) = delete;

    virtual void beExecuted() const override;
};

#endif