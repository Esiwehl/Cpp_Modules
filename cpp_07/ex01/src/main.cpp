#include "iter.hpp"
#include <iostream>

// void printElement(char element){
//     std::cout << element << " ";
// }

void printElement(int element){
    std::cout << element << " ";
}

void charTester(){
    char arr[] = {'h', 'e', 'y'};

    size_t length = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Array elements: ";
    iter(arr, length, printElement);
    std::cout << std::endl;

    std::cout << "Array elements capitalized: ";
    iter(arr, length, [](char& element) {toupper(element);});
    iter(arr, length, printElement);
    std::cout << std::endl;
}

void intTester(){
    int arr[] = {1, 2, 3, 4, 5};
    
    size_t length = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array elements: ";
    iter(arr, length, printElement);
    std::cout << std::endl;

    std::cout << "Array elements doubled: ";
    iter(arr, length, [](int& x) { x *= 2; });
    iter(arr, length, printElement);
    std::cout << std::endl;
}

int main() {
    intTester();
    // charTester();

    return 0;
}
