#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>

# include "AForm.hpp"

class Intern {
private:
    typedef AForm* (*FormCreator)(const std::string&);
    struct FormEntry {
        std::string formName;
        FormCreator creator;
    };
    static FormEntry formEntries[];

public:
    Intern() = default;
    Intern(const Intern& other) = default;
    ~Intern() = default;

    Intern& operator=(const Intern& other) = default;

    AForm* makeForm(const std::string& formName, const std::string& formTarget);
    static AForm* createShrubberyForm(const std::string& target);
    static AForm* createRobotomyForm(const std::string& target);
    static AForm* createPresidentialForm(const std::string& target);
};

#endif