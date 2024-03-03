#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook {
private:
	int	_contactIdx;
	int _contactCount;
	Contact contacts[8];

public:
    Phonebook();
    void ADD();
    void SEARCH();
    void EXIT();
};

#endif