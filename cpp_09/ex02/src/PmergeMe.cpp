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

	std::vector<int> mainSequence;
	for (const auto& pair : pairs) {
		mainSequence.push_back(pair.second);
	}
	std::sort(mainSequence.begin(), mainSequence.end()); 

	for (const auto& pair : pairs) {
		auto it = std::upper_bound(mainSequence.begin(), mainSequence.end(), pair.first);
		mainSequence.insert(it, pair.first); 
	}

	vec = mainSequence;
}

void PmergeMe::fordJohnsonSortList(std::list<int>& lst) {
	if (lst.size() <= 1) return;

	std::list<std::pair<int, int>> pairs;
	auto it = lst.begin();
	while (it != lst.end()) {
		int first = *it++;
		int second = (it != lst.end()) ? *it++ : first;
		pairs.push_back(std::minmax(first, second)); 
	}

	std::list<int> mainSequence;
	for (const auto& pair : pairs) {
		mainSequence.push_back(pair.second);
	}
	mainSequence.sort(); 

	for (const auto& pair : pairs) {
		auto insertPos = std::upper_bound(mainSequence.begin(), mainSequence.end(), pair.first);
		mainSequence.insert(insertPos, pair.first);
	}

	lst = mainSequence;
}

// Optimized Ford-Johnson for std::list
void PmergeMe::fordJohnsonSort(std::list<int>& lst) {
    if (lst.size() <= 1) return;

    // Step 1: Pair elements and sort each pair with direct iterator manipulation
    std::list<std::pair<int, int>> pairs;
    auto it = lst.begin();
    while (it != lst.end()) {
        int first = *it++;
        int second = (it != lst.end()) ? *it++ : first;
        pairs.push_back(std::minmax(first, second)); 
    }

    // Step 2: Merge larger elements directly using list's efficient insertion
    std::list<int> mainSequence;
    for (const auto& pair : pairs) {
        mainSequence.push_back(pair.second);
    }
    mainSequence.sort();

    // Step 3: Efficient insertion using splice
    for (const auto& pair : pairs) {
        auto insertPos = std::find_if(mainSequence.begin(), mainSequence.end(), 
                                      [&pair](int val) { return val > pair.first; });
        mainSequence.insert(insertPos, pair.first);
    }

    lst = std::move(mainSequence);
}

// Optimized Ford-Johnson for std::vector
void PmergeMe::fordJohnsonSort(std::vector<int>& vec) {
    if (vec.size() <= 1) return;

    // Step 1: Pair elements and sort each pair, use direct indexing
    std::vector<std::pair<int, int>> pairs;
    for (size_t i = 0; i < vec.size() - 1; i += 2) {
        pairs.push_back(std::minmax(vec[i], vec[i + 1])); 
    }
    if (vec.size() % 2 != 0) {
        pairs.push_back({vec.back(), vec.back()});
    }

    // Step 2: Use contiguous memory access for merging
    std::vector<int> mainSequence;
    mainSequence.reserve(vec.size()); // Reserve memory upfront to avoid reallocations
    for (const auto& pair : pairs) {
        mainSequence.push_back(pair.second);
    }
    std::sort(mainSequence.begin(), mainSequence.end());

    // Step 3: Minimize insertion costs by batching insertions
    for (const auto& pair : pairs) {
        auto it = std::upper_bound(mainSequence.begin(), mainSequence.end(), pair.first);
        mainSequence.insert(it, pair.first);
    }

    vec = std::move(mainSequence); // Use move semantics to optimize assignment
}

void PmergeMe::sortOptimized(std::vector<int>& vec) {
	auto start = std::chrono::high_resolution_clock::now();
	fordJohnsonSort(vec);
	auto end = std::chrono::high_resolution_clock::now();
	double duration = std::chrono::duration<double, std::micro>(end - start).count();
	std::cout << "Time to process with std::vector: " << duration << " µs" << std::endl;
}

void PmergeMe::sortOptimized(std::list<int>& lst) {
	auto start = std::chrono::high_resolution_clock::now();
	fordJohnsonSort(lst);
	auto end = std::chrono::high_resolution_clock::now();
	double duration = std::chrono::duration<double, std::micro>(end - start).count();
	std::cout << "Time to process with std::vector: " << duration << " µs" << std::endl;
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
