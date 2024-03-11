#include <iostream>
#include <string>

#include "Harl.hpp"

int main (int argc, char **argv){
	
	if (argc != 2){
		std:: cerr << "Incorrect usage, try: ./harl <DEBUG|ERROR|INFO|WARNING>" << std::endl;
		return 1;
	}

	Harl harl;
	harl.complain(argv[1]);

	return 0;
}