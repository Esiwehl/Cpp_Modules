#include <iostream>
#include <cctype>
#include <string>
#include <sstream>

#include "Contact.hpp"

void Contact::setDetails(const std::string& fname, const std::string& lname, const std::string& nname,
		const std::string& secret, const std::string& number){
		this->firstname = fname;
		this->lastname = lname;
		this->nickname = nname;
		this->darkestSecret = secret;
		this->number = number;
	}

std::string Contact::getFirstname(){
	return firstname;
}

std::string Contact::getLastname(){
	return lastname;
}
std::string Contact::getNickname(){
	return nickname;
}
std::string Contact::getDarkestSecret(){
	return darkestSecret;
}
std::string Contact::getNumber(){
	return number;
}
void Contact::showContact(){
		std::cout << "Name = " << firstname << " \'" << nickname << "\' " << lastname << std::endl;
		std::cout << "Secret = " << darkestSecret << std::endl;
		std::cout << "Number = " << number << std::endl;
	}