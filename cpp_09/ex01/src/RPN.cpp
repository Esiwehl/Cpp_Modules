#include "RPN.hpp"
#include <sstream>
#include <stdexcept>

bool RPN::isOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::performOperation(int a, int b, char op) {
	switch (op) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': 
			if (b == 0) throw std::runtime_error("Error: Division by zero");
			return a / b;
		default: 
			throw std::invalid_argument("Invalid operator");
	}
}

int RPN::evaluate(const std::string &expression) {
	std::stack<int> stack;
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) {
		if (token.size() == 1 && isOperator(token[0])) {
			if (stack.size() < 2) {
				throw std::runtime_error("Error: Not enough operands");
			}
			
			int b = stack.top(); stack.pop();
			int a = stack.top(); stack.pop();
			int result = performOperation(a, b, token[0]);
			stack.push(result);
		} else {
			try {
				int number = std::stoi(token);
				stack.push(number);
			} catch (const std::invalid_argument&) {
				throw std::runtime_error("Error: Invalid input");
			}
		}
	}

	if (stack.size() != 1) {
		throw std::runtime_error("Error: Invalid RPN expression");
	}

	return stack.top();
}
