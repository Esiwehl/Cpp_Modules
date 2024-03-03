#include <iostream>
#include <limits>
#include <cctype>
#include <string>
#include <sstream>

#include "ioHelpers.hpp"
#include "Phonebook.hpp"
#include "Contact.hpp"

int main(){
	Phonebook myBook;
	std::string input;

	while (1) {
		std::cout << "What would you like to do?" << std::endl;
		std::cin >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
		if (input == ADD_STR){
			myBook.ADD();
		}
		else if (input == SEARCH_STR){
			myBook.SEARCH();
		}
		else if (input == Q_STR){
			myBook.EXIT();
			return (0);
		}
		else {
			std::cout << "Please choose a valid action :D" << std::endl;
			std::cout << "ADD, SEARCH or EXIT to exit." << std::endl;
			std::cout << "Let's try it again." << std::endl;
		}
	}
}
