#include <string>
#include <iostream>

int main (void){
    std::string str = "HI THIS IS BRAIN";

    std::string* strPtr;
    std::string& strRef = str;

    strPtr = &str;

    std::cout << "---- Memory addresses:\n"
				<< "Address of string:\t" << &str << "\n"
				<< "Address held by strPtr:\t" << strPtr << "\n"
				<< "Address held by strRef:\t" << &strRef << std::endl;

	std::cout << "\n---- Values:\n"
				<< "Value of string:\t\t[" << str << "]\n"
				<< "Value pointed to by strPtr:\t[" << *strPtr << "]\n"
				<< "Value pointed to by strRef:\t[" << strRef << "]" << std::endl;
}