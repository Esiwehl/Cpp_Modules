#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <list>

void testComplexIterations() {
	std::cout << "Test Complex Iterations:" << std::endl;

	MutantStack<int> mstack;
	for (int i = 1; i <= 10; ++i) {
		mstack.push(i);
	}

	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ) {
		std::cout << "Current value: " << *it << std::endl;
		if (*it % 2 == 0) {
			std::cout << "Removing even value: " << *it << std::endl;
			it = mstack.erase(it);
		} else {
			++it;
		}
	}

	std::cout << "Stack after removal of even numbers:" << std::endl;
	for (int value : mstack) {
		std::cout << value << " ";
	}
	std::cout << std::endl << "-------------------------------------------" << std::endl;
}

void testExceptionHandling() {
	std::cout << "Test Exception Handling and Edge Cases:" << std::endl;

	MutantStack<int> mstack;

	try {
		std::cout << "Iterating over an empty stack:" << std::endl;
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
			std::cout << *it << std::endl;
		}
	} catch (const std::exception& e) {
		std::cerr << "Exception caught while iterating empty stack: " << e.what() << std::endl;
	}

	for (int i = 1; i <= 5; ++i) {
		mstack.push(i);
	}

	std::cout << "Initial stack state:" << std::endl;
	for (int num : mstack) {
		std::cout << num << " ";
	}
	std::cout << std::endl;

	try {
		// Mutaties tijdens iteratie (dit kan tot onvoorspelbare situaties leiden)
		std::cout << "Modifying stack during iteration:" << std::endl;
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
			std::cout << *it << std::endl;
			if (*it == 3) {
				std::cout << "Modifying stack (pushing 99) during iteration" << std::endl;
				mstack.push(99);  // Verandert de stack tijdens iteratie
			}
		}
	} catch (const std::exception& e) {
		std::cerr << "Exception caught during modification: " << e.what() << std::endl;
	}

	std::cout << std::endl << "-------------------------------------------" << std::endl;
}


void compareWithStdStack() {
	std::cout << "Comparison with std::stack:" << std::endl;

	// Maak een normale std::stack
	std::stack<int> sstack;
	MutantStack<int> mstack;

	for (int i = 0; i < 5; ++i) {
		sstack.push(i);
		mstack.push(i);
	}

	std::cout << "Comparing size: " << std::endl;
	std::cout << "std::stack size: " << sstack.size() << std::endl;
	std::cout << "MutantStack size: " << mstack.size() << std::endl;

	std::cout << "Comparing top elements: " << std::endl;
	std::cout << "std::stack top: " << sstack.top() << std::endl;
	std::cout << "MutantStack top: " << mstack.top() << std::endl;

	sstack.pop();
	mstack.pop();

	std::cout << "After one pop operation: " << std::endl;
	std::cout << "std::stack size: " << sstack.size() << std::endl;
	std::cout << "MutantStack size: " << mstack.size() << std::endl;

	// Itereren door de MutantStack
	std::cout << "Iterating through MutantStack:" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl << "-------------------------------------------" << std::endl;
}

void testEraseWithList() {
	std::cout << std::endl << "Testing Erase with MutantStack and std::list:" << std::endl;

	MutantStack<int> mstack;
	for (int i = 1; i <= 10; ++i) {
		mstack.push(i);
	}

	std::cout << "MutantStack before erase:" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ) {
		if (*it % 2 == 0) {
			it = mstack.erase(it); // Verwijder het element via de erase() van MutantStack
		} else {
			++it;
		}
	}

	std::cout << "MutantStack after erasing even numbers:" << std::endl;
	for (int num : mstack) {
		std::cout << num << " ";
	}
	std::cout << std::endl << std::endl;

	std::list<int> myList;
	for (int i = 1; i <= 10; ++i) {
		myList.push_back(i);
	}

	std::cout << "std::list before erase:" << std::endl;
	for (std::list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	for (std::list<int>::iterator it = myList.begin(); it != myList.end(); ) {
		if (*it % 2 == 0) {
			it = myList.erase(it);
		} else {
			++it;
		}
	}

	std::cout << "std::list after erasing even numbers:" << std::endl;
	for (int num : myList) {
		std::cout << num << " ";
	}
	std::cout << std::endl << std::endl;
}


void subject() {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
}

int main() {
	subject();
	testEraseWithList();

	// testComplexIterations();
	// testExceptionHandling();
	// compareWithStdStack();

	return 0;
}
