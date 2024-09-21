#include <string>
#include <sstream>
#include <cctype>

bool isNumber(const std::string& s) {
	for (char c : s) {
		if (!std::isdigit(c)) return false;
	}
	return true;
}

bool isValidDate(const std::string& date) {
	if (date.length() != 10) return false;
	if (date[4] != '-' || date[7] != '-') return false;

	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);

	if (!isNumber(yearStr) || !isNumber(monthStr) || !isNumber(dayStr))
		return false;

	int year = std::stoi(yearStr);
	int month = std::stoi(monthStr);
	int day = std::stoi(dayStr);

	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
		return false;
	}

	if (month == 2) {
		bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if ((isLeapYear && day > 29) || (!isLeapYear && day > 28)) {
			return false;
		}
	}

	return true;
}
