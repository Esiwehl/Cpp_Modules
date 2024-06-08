#include <iostream>
#include "Array.hpp"

int main() {
	try {
		Array<int> arr1;
		std::cout << "Size of arr1: " << arr1.size() << std::endl;

		Array<int> arr2(5);
		std::cout << "Size of arr2: " << arr2.size() << std::endl;

		Array<int> arr3(arr2);
		std::cout << "Size of arr3 (copied from arr2): " << arr3.size() << std::endl;

		Array<int> arr4;
		arr4 = arr2;
		std::cout << "Size of arr4 (assigned from arr2): " << arr4.size() << std::endl;

		for (unsigned int i = 0; i < arr2.size(); ++i) {
			arr2[i] = i * 10;
		}
		for (unsigned int i = 0; i < arr2.size(); ++i) {
			std::cout << "arr2[" << i << "] = " << arr2[i] << std::endl;
		}

		arr2 = Array<int>();
		std::cout << "Accessing element in cleared arr2:" << std::endl;
		std::cout << arr2[3] << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
