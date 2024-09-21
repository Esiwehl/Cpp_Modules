#include "Span.hpp"

Span::Span(unsigned int n): _max(n) {}

void Span::addNumber(int num) {
	if (_numbers.size() >= _max){
		throw std::out_of_range("Reached max size, couldn't add number..");
	}
	_numbers.push_back(num);
}

int Span::shortestSpan() const {
	if (_numbers.size() < 2)
		throw NoSpanPossibleException();
	
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	int min_span = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); ++i) {
		min_span = std::min(min_span, sorted[i] - sorted[i - 1]);
	}
	return min_span;
}

int Span::longestSpan() const {
	if (_numbers.size() < 2)
		throw NoSpanPossibleException();

	int min_value = *std::min_element(_numbers.begin(), _numbers.end());
	int max_value = *std::max_element(_numbers.begin(), _numbers.end());
	return max_value - min_value;
}

const std::vector<int>& Span::getNumbers() const {
	return _numbers;
}
