#include <iostream>
#include <string>

class Contact {
	private:
	std::string name;
	std::string address;
	std::string number;

	public:
	void setName(std::string x){
		name = x;
	}
	std::string getName(){
		return name;
	}

	void setAddress(std::string x){
		address = x;
	};
	std::string getAddress(){
		return address;
	}

	void setNumber(std::string x){
		number = x;
	}
	std::string getNumber(){
		return number;
	}
};

class Phonebook {
	private:
	int _contact_count;
	int *contacts[8];

	public:
	void ADD(){
		std::cout << "WE ARE ADDDING" << std::endl;
	}

	void SEARCH(){
		std::cout << "IN SEARCH OF SOMETHING" << std::endl;
	}

	void EXIT(){
		std::cout << "Exiting" << std::endl;
	}

	Phonebook(){
	
	}
};

int main(){
	Phonebook my_book;
	std::string input;

	while (1) {
		std::cout << "What would you like to do?" << std::endl;
		std::cin >> input;

		if (input == "ADD"){
			my_book.ADD();
		}
		else if (input == "SEARCH"){
			my_book.SEARCH();
		}
		else if (input == "EXIT"){
			my_book.EXIT();
			return (0);
		}
		else {
			std::cout << "Please choose a valid action :D" << std::endl;
			std::cout << "ADD, SEARCH or EXIT to exit." << std::endl;
			std::cout << "Let's try it again." << std::endl;
		}
	}
}
