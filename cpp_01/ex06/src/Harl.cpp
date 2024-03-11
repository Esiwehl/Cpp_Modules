#include "Harl.hpp"
#include "Harl.hpp"

void Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

int Harl::getLevel(std::string level) {
	if (level == "DEBUG")
		return DEBUG;
	if (level == "INFO")
		return INFO;
	if (level == "WARNING")
		return WARNING;
	if (level == "ERROR")
		return ERROR;
	return INVALID;
}

void Harl::complain(std::string level) {
	switch (getLevel(level)) {
		case DEBUG:
			debug();
		case INFO:
			info();
		case WARNING:
			warning();
		case ERROR:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
