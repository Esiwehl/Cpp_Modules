#include "PmergeMe.hpp"
#include <vector>
#include <list>
#include <iostream>

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Usage: ./PmergeMe <numbers>" << std::endl;
		return 1;
	}

	std::list<int>		lst;
	std::vector<int>	vec;

	for (int i = 1; i < argc; ++i) {
		try {
			int num = std::stoi(argv[i]);
			vec.push_back(num);
			lst.push_back(num);
		} catch (const std::exception& e) {
			std::cerr << "Invalid input: " << argv[i] << " is not a valid number." << std::endl;
			return 1;
		}
	}

	PmergeMe sorter;
	sorter.sortVector(vec);
	sorter.sortList(lst);

	// sorter.printResults(vec, lst);
	std::cout << std::endl << "_____________________________" << std::endl;

	PmergeMe sorter2;
	sorter2.sortOptimized(vec);
	sorter2.sortOptimized(lst);

	// sorter2.printResults(vec, lst);

	return 0;
}
