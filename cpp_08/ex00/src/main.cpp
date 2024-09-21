#include "Easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main() {
	// Test with a vector
	std::vector<int> vec;
	vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
	try {
		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << "Found in vector: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	// Test with a list
	std::list<int> lst;
	lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);

	try {
		std::list<int>::iterator it = easyfind(lst, 25);
		std::cout << "Found in list: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	// Test with a array
	std::deque<int> deq;
	deq.push_back(100);
    deq.push_back(200);
    deq.push_back(300);
    deq.push_back(400);

	try {
		std::deque<int>::iterator it = easyfind(deq, 100);
		std::cout << "Found in array: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
