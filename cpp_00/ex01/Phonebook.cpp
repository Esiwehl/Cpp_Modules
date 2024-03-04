#include "Phonebook.hpp"
#include "ioHelpers.hpp"
#include <iostream>
#include <limits>
#include <cctype>
#include <sstream>

Phonebook::Phonebook() : _contactIdx(0), _contactCount(0) {}

void Phonebook::ADD(){
		Contact	newContact;
		std::string fname, lname, nname, secret, number;

		promptInput("Enter their firstname: ", fname);
		promptInput("Enter their lastname: ", lname);
		promptInput("Enter their nickname: ", nname);
		promptInput("Enter their darkest secret: ", secret);
		promptInput("Enter their number: ", number, isInvalidNumber);

		newContact.setDetails(fname, lname, nname, secret, number);
		
		_contactIdx = _contactCount % 8;
		contacts[_contactIdx] = newContact;
		_contactCount++;
        std::cout << "Succesfully added new Contact" << std::endl;
	}

void Phonebook::SEARCH(){
		int index;
	
		std::cout << "Index     |First Name|Last Name |Nickname  " << std::endl;
		int max = (_contactCount < 8) ? _contactCount : 8;
		for (int idx = 0; idx < max; idx++){
			std::stringstream ss;
			ss << idx;
			std::string idxStr = ss.str();
			std::cout << formatColumn(idxStr) << '|'
                      << formatColumn(contacts[idx].getFirstname()) << '|'
                      << formatColumn(contacts[idx].getLastname()) << '|'
                      << formatColumn(contacts[idx].getNickname()) << std::endl;
		}

		std::cout << "Enter the index of the contact you'd like to expose: " << std::endl;
		std::cin >> index;
		if (index < 0 || (index >= _contactCount && index < 8) || std::cin.fail()) {
          std::cin.clear();
		  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "Invalid index." << std::endl;
		}
		else {
            contacts[index].showContact();
        }
	}

void Phonebook::EXIT(){
		std::cout << "Exiting" << std::endl;
	}