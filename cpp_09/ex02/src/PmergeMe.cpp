#include "PmergeMe.hpp"
#include <algorithm>
#include <iterator>

void PmergeMe::fordJohnsonSortVector(std::vector<int>& vec) {
	if (vec.size() <= 1) return;

	std::vector<std::pair<int, int>> pairs;
	for (size_t i = 0; i < vec.size() - 1; i += 2) {
		pairs.push_back(std::minmax(vec[i], vec[i + 1])); 
	}
	if (vec.size() % 2 != 0) {
		pairs.push_back({vec.back(), vec.back()});
	}

	std::vector<int> biggestValues;
	for (const std::pair<int, int>& pair : pairs) {
		biggestValues.push_back(pair.second);
	}
	std::sort(biggestValues.begin(), biggestValues.end()); 

	for (const std::pair<int, int>& pair : pairs) {
		std::vector<int>::iterator it = std::upper_bound(biggestValues.begin(), biggestValues.end(), pair.first);
		biggestValues.insert(it, pair.first); 
	}

	vec = biggestValues;
}

void PmergeMe::fordJohnsonSortList(std::list<int>& lst) {
	if (lst.size() <= 1) return;

	std::list<std::pair<int, int>> pairs;
	std::list<int>::iterator it = lst.begin();
	while (it != lst.end()) {
		int first = *it++;
		int second = (it != lst.end()) ? *it++ : first;
		pairs.push_back(std::minmax(first, second)); 
	}

	std::list<int> biggestValues;
	for (const struct std::pair<int, int>& pair : pairs) {
		biggestValues.push_back(pair.second);
	}
	biggestValues.sort(); 

	for (const struct std::pair<int, int>& pair : pairs) {
		std::list<int>::iterator insertPos = std::upper_bound(biggestValues.begin(), biggestValues.end(), pair.first);
		biggestValues.insert(insertPos, pair.first);
	}

	lst = biggestValues;
}

void PmergeMe::fordJohnsonSort(std::list<int>& lst) {
    if (lst.size() <= 1) return;

    std::list<std::pair<int, int>> pairs;
    std::list<int>::iterator it = lst.begin();
    while (it != lst.end()) {
        int first = *it++;
        int second = (it != lst.end()) ? *it++ : first;
        pairs.push_back(std::minmax(first, second)); 
    }

    std::list<int> biggestValues;
    for (const struct std::pair<int, int>& pair : pairs) {
        biggestValues.push_back(pair.second);
    }
    biggestValues.sort();

    for (const struct std::pair<int, int>& pair : pairs) {
        std::list<int>::iterator insertPos = std::find_if(biggestValues.begin(), biggestValues.end(), 
                                      [&pair](int val) { return val > pair.first; });
        biggestValues.insert(insertPos, pair.first);
    }

    lst = std::move(biggestValues);
}

void PmergeMe::fordJohnsonSort(std::vector<int>& vec) {
    if (vec.size() <= 1) return;

    std::vector<std::pair<int, int>> pairs;
    for (size_t i = 0; i < vec.size() - 1; i += 2) {
        pairs.push_back(std::minmax(vec[i], vec[i + 1])); 
    }
    if (vec.size() % 2 != 0) {
        pairs.push_back({vec.back(), vec.back()});
    }

    // Step 2: Use contiguous memory access for merging
    std::vector<int> biggestValues;
    biggestValues.reserve(vec.size()); // Reserve memory upfront to avoid reallocations
    for (const std::pair<int, int>& pair : pairs) {
        biggestValues.push_back(pair.second);
    }
    std::sort(biggestValues.begin(), biggestValues.end());

    // Step 3: Minimize insertion costs by batching insertions
    for (const std::pair<int, int>& pair : pairs) {
        std::vector<int>::iterator it = std::upper_bound(biggestValues.begin(), biggestValues.end(), pair.first);
        biggestValues.insert(it, pair.first);
    }

    vec = std::move(biggestValues); // Use move semantics to optimize assignment
}

void PmergeMe::sortOptimized(std::vector<int>& vec) {
	std::chrono::_V2::system_clock::time_point start = std::chrono::high_resolution_clock::now();
	fordJohnsonSort(vec);
	std::chrono::_V2::system_clock::time_point end = std::chrono::high_resolution_clock::now();
	double duration = std::chrono::duration<double, std::micro>(end - start).count();
	std::cout << "Time to process with std::vector: " << duration << " µs" << std::endl;
}

void PmergeMe::sortOptimized(std::list<int>& lst) {
	auto start = std::chrono::high_resolution_clock::now();
	fordJohnsonSort(lst);
	auto end = std::chrono::high_resolution_clock::now();
	double duration = std::chrono::duration<double, std::micro>(end - start).count();
	std::cout << "Time to process with std::list: " << duration << " µs" << std::endl;
}

void PmergeMe::sortVector(std::vector<int>& vec) {
	auto start = std::chrono::high_resolution_clock::now();
	fordJohnsonSortVector(vec);
	auto end = std::chrono::high_resolution_clock::now();
	double duration = std::chrono::duration<double, std::micro>(end - start).count();
	std::cout << "Time to process with std::vector: " << duration << " µs" << std::endl;
}

void PmergeMe::sortList(std::list<int>& lst) {
	auto start = std::chrono::high_resolution_clock::now();
	fordJohnsonSortList(lst);
	auto end = std::chrono::high_resolution_clock::now();
	double duration = std::chrono::duration<double, std::micro>(end - start).count();
	std::cout << "Time to process with std::list: " << duration << " µs" << std::endl;
}

void PmergeMe::printResults(const std::vector<int>& vec, const std::list<int>& lst) {
	std::cout << "Sorted vector: ";
	for (const int& num : vec) {
		std::cout << num << " ";
	}
	std::cout << std::endl;

	std::cout << "Sorted list: ";
	for (const int& num : lst) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
}
