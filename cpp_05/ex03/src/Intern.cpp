#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

AForm* shrubberyForm(const std::string& target) {
    return (new ShrubberyCreationForm(target));
}

AForm* robotomyForm(const std::string& target) {
    return (new RobotomyRequestForm(target));
}

AForm* presidentialForm(const std::string& target) {
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget) {
    int pos;
    std::string[3]
    
    for (pos = 0; formName != formArray[pos]; pos++)
    
    switch (pos)
    {
    case 0:

        break;
    case 1:
        
        break;
    case 2:

        break;
    default:

        break;
    }
}