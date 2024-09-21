#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>

class RPN {
public:
	int evaluate(const std::string &expression);

private:
	bool isOperator(char c);
	int performOperation(int a, int b, char op);
};

#endif
