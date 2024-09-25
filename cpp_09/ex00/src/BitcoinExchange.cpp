#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <limits>

void BitcoinExchange::loadHistoricalData(const std::string &filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error: could not open historical data file." << std::endl;
		return;
	}

	std::string line;
	while (getline(file, line)) {
		std::stringstream ss(line);
		std::string date;
		float price;

		if (getline(ss, date, ',') && ss >> price) {
			_historical_data[date] = price;
		}
	}
	file.close();
}

float BitcoinExchange::getBitcoinValueOnDate(const std::string &date) {
	std::map<std::string, float>::iterator it = _historical_data.lower_bound(date);
	if (it == _historical_data.end() || it->first > date) {
		if (it != _historical_data.begin()) {
			--it;
		}
	}
	return it->second;
}

void BitcoinExchange::processInputFile(const std::string &filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error: could not open input file." << std::endl;
		return;
	}

	if (_historical_data.empty()) {
		std::cerr << "No database found, terminating here." << std::endl;
		return;
	}

	std::string line;
	if (getline(file, line)) {
		//Skipping first line
	}
	while (getline(file, line)) {
		std::stringstream ss(line);
		std::string date;
		float value;

		if (getline(ss, date, '|')) {
			date = date.substr(0, date.find_last_not_of(" ") + 1);
			date = date.substr(date.find_first_not_of(" "));
			ss >> value;

			if (!isValidDate(date)) {
				std::cerr << "Error: invalid date format => " << date << std::endl;
				continue;
			}

			if (value < 0 || value > 1000) {
				std::string valStr = ((value < 0) ? "not a positive value" : "too large a number");
				std::cerr << "Error: " << valStr << std::endl;
				continue;
			}

			float bitcoinPrice = getBitcoinValueOnDate(date);
			std::cout << date << " => " << value << " = " << value * bitcoinPrice << std::endl;
		} else {
			std::cerr << "Error: bad input format." << std::endl;
		}
	}
	file.close();
}
