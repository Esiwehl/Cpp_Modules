#include <iostream>
#include <limits>
#include <string>
#include <sstream>

#define ADD_STR "add"
#define SEARCH_STR "search"
#define Q_STR "quit"

class Contact {
	private:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string darkestSecret;
	std::string number;

	public:
	void setName(std::string x, std::string y){
		this->firstname = x;
		this->lastname = y;
	}
	std::string getFirstname(){
		return firstname;
	}
	std::string getLastname(){
		return lastname;
	}

	void setNickname(std::string x){
		this->nickname = x;
	};
	std::string getNickname(){
		return nickname;
	}

	void setDarkestSecret(std::string x){
		this->darkestSecret = x;
	}
	std::string getDarkestSecret(){
		return darkestSecret;
	}

	void setNumber(std::string x){
		this->number = x;
	}
	std::string getNumber(){
		return number;
	}

	void showContact(){
		std::cout << "Name = " << firstname << " \'" << nickname << "\' " << lastname << std::endl;
		std::cout << "Secret = " << darkestSecret << std::endl;
		std::cout << "Number = " << number << std::endl;
	}
};

int isValidNumber(const std::string& number)
{
	for (size_t idx = 0; idx < number.length(); idx++){
		if (!isdigit(number[idx]))
			return false;
	}
	return true;
}

std::string formatColumn(const std::string input){
	if (input.length() > 10)
		return input.substr(0,9) + ".";
	return std::string(10 - input.length(), ' ') + input;
}

// Add a check that checks validity of input; only digits, only letters.
class Phonebook {
	private:
	int _contactCount;
	Contact contacts[8];

	public:
	void ADD(){
		Contact	newContact;
		std::string fname, lname, nickname, secret, number;

		if (_contactCount == 8){
			std::cout << "Sorry phonebook is full.." << std::endl;
			return;
		}

		newContact.showContact();
	
    	std::cout << "Enter their first name: ";
    	std::getline(std::cin, fname);

    	std::cout << "Enter their last name: ";
    	std::getline(std::cin, lname);
	
		std::cout << "Enter their nickname: ";
    	std::getline(std::cin, nickname);

		std::cout << "Enter their darkest secret: ";
    	std::getline(std::cin, secret);

		std::cout << "Enter their number: ";
    	std::getline(std::cin, number);

		if (!isValidNumber(number)){
			std::cout << "Invalid input: " << number << std::endl;
			std::cout << "Please only use digits."<< std::endl;
			return;
		}

		newContact.setName(fname, lname);
		newContact.setNickname(nickname);
		newContact.setDarkestSecret(secret);
		newContact.setNumber(number);
		contacts[_contactCount] = newContact;
		
		std::cout << _contactCount << " = ";
		contacts[_contactCount].showContact();
		_contactCount++;
	}

	void SEARCH(){
		int index;
	
		std::cout << "Index     |First Name|Last Name |Nickname  " << std::endl;
		for (int idx = 0; idx < _contactCount; idx++){
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
		if (index < 0 || index >= _contactCount || std::cin.fail()) {
          std::cin.clear();
		  std::cin.ignore(std::numeric_limits<std::streamsize>::max());
          std::cout << "Invalid index." << std::endl;
		}
		else {
            contacts[index].showContact();
        }
	}

	void EXIT(){
		std::cout << "Exiting" << std::endl;
	}

	int getCount()
	{
		return _contactCount;
	}

	Phonebook() : _contactCount(0) {}; 
};

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
			std::cout << "add, search or quit to quit." << std::endl;
			std::cout << "Let's try it again." << std::endl;
		}
	}
}
