#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
    const std::string _target;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    virtual ~RobotomyRequestForm();

    RobotomyRequestForm& operator=(const RobotomyRequestForm& other) = delete;

    virtual void beExecuted() const override;
};

#endif