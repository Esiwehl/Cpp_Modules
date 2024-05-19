#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::FormEntry Intern::formEntries[] = {
    {"PresidentialPardon", &Intern::createPresidentialForm},
    {"RobotomyRequest", &Intern::createRobotomyForm},
    {"ShrubberyCreation", &Intern::createShrubberyForm}
};


AForm* Intern::createShrubberyForm(const std::string& target) {
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomyForm(const std::string& target) {
    return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidentialForm(const std::string& target) {
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget) {
    const int numForms = sizeof(formEntries) / sizeof(FormEntry);
    for (int i = 0; i < numForms; ++i) {
        if (formEntries[i].formName == formName) {
            std::cout << "Intern creates " + formEntries[i].formName + "Form" << std::endl;
        return formEntries[i].creator(formTarget);
    }
}

    std::cerr << "Intern could not create "+ formName +"Form, because it's unknown" << std::endl;
    return nullptr;
}