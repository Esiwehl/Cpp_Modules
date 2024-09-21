#include "Span.hpp"
#include <iostream>

int main() {
	try {
		Span sp(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		// sp.addNumber(44);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // Verwacht output: 2
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;  // Verwacht output: 14

		// Testing bulk addition of numbers
		Span sp2(10000);
		std::vector<int> bulk_numbers(50, 2);
		sp2.addNumbers(bulk_numbers.begin(), bulk_numbers.end());
		int count = 0;
		for (int num : sp2.getNumbers()) {
			std::cout << "Element " << count << ": " << num << std::endl;
			++count;
		}
		std::cout << "Longest span in bulk add: " << sp2.longestSpan() << std::endl; // Verwacht output: 0
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
