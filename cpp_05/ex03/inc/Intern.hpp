#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>

# include "AForm.hpp"

class Intern {
public:
    Intern() = default;
    Intern(const Intern& other) = default;
    ~Intern() = default;

    Intern& operator=(const Intern& other) = default;

    AForm* makeForm(const std::string& formName, const std::string& formTarget);
};

#endif