#include <string>
#include <iostream>

int instructions(char *str){
    std::cout << "Incorrect usage:" << str <<
        " <filename> <search> <replace>" << std::endl;
    return 1;
}

int main(int argc, char **argv){
    if (argc != 4)
        return instructions(argv[0]);
    
}