#include "Brain.hpp"
#include <algorithm>

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
    for (int i = 0; i < 100; ++i) {
        ideas[i] = "Idea #" + std::to_string(i);
    }
}

Brain::Brain(const Brain& other) {
	std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; ++i) {
        this->ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

// Brain& Brain::operator=(const Brain& other) {
//     if (this != &other) {
//         std::copy(std::begin(other.ideas), std::end(other.ideas), std::begin(this->ideas));
//     }
//     return *this;
// }

std::string Brain::getIdea(int idx) const {
	if (idx < 0)
		idx *= -1;
	if (idx > 99)
		idx %= 100;
	// std::cout << "Accessing idx  = " << idx << std::endl;
	return (ideas[idx]);
}

void Brain::setIdea(int idx, std::string idea) {
		if (idx < 0)
		idx *= -1;
	if (idx > 99)
		idx %= 100;
	// std::cout << "Modifying idx  = " << idx << std::endl;
	ideas[idx] = idea;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}
