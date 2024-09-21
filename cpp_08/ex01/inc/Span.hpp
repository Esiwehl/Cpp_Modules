#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>
# include <algorithm>
# include <limits>
# include <iterator>

class Span {
	private:
		unsigned int _max;
		std::vector<int> _numbers;

	public:
		Span(unsigned int n);
		Span(const Span& other) = delete;
		Span& operator=(const Span& other) = delete;
		~Span() = default;

		void addNumber(int number);

		template <typename Iter>
		void addNumbers(Iter begin, Iter end) {
			if (_numbers.size() + std::distance(begin, end) > _max)
				throw std::out_of_range("Vector not big enough for this many _numbers");

			_numbers.insert(_numbers.end(), begin, end);
		}

		int shortestSpan() const;
		int longestSpan() const;

		const std::vector<int>& getNumbers() const;

		class NoSpanPossibleException : public std::exception {
			const char* what() const throw() {
				return "Too few numbers to get a span..";
			}
		};
};

#endif