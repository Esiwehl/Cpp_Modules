#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <chrono>

class PmergeMe {
public:
	PmergeMe() = default;
	PmergeMe(const PmergeMe& other) = default;
	PmergeMe& operator=(const PmergeMe& other) = default;
	~PmergeMe() = default;

	void sortOptimized(std::list<int>& lst);
	void sortOptimized(std::vector<int>& vec);
	void sortVector(std::vector<int>& vec);
	void sortList(std::list<int>& lst);
	void printResults(const std::vector<int>& vec, const std::list<int>& lst);

private:
	void fordJohnsonSort(std::list<int>& lst);
	void fordJohnsonSort(std::vector<int>& vec);
	void fordJohnsonSortVector(std::vector<int>& vec);
	void fordJohnsonSortList(std::list<int>& lst);
};

#endif
