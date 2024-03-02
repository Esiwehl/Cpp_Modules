#include <iostream>

int main(int argc, char *argv[]){
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int idx = 1; idx < argc; idx++){
        std::string str(argv[idx]);
        for (std::string::iterator it = str.begin(); it != str.end(); it++){
			*it = std::toupper(*it);
	    }
        std::cout << str << std::endl;
    }
    return 0;
}

/*                  RANGE BASED FOR-LOOPS
Introduced in C++11 and in essence provide a more concise and readable way of iterating over elements in a range, such as elements in an array, characters in a string or items in a container (std::vector and std::list).

A container is pretty much any data holder of a collection of data. 

An example using range-based for loops.
int main(int argc, char *argv[]){
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int idx = 1; idx < argc; idx++){
        std::string str = argv[idx];
        for (char &c : str) {
            std::cout << (char) toupper(c);
        }
    }
    return 0;
}*/
