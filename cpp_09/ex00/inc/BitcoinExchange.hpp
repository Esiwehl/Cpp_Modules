#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <string>

class BitcoinExchange {
private:
	std::map<std::string, float> _historical_data;

public:
	void loadHistoricalData(const std::string &filename);
	float getBitcoinValueOnDate(const std::string &date);
	void processInputFile(const std::string &filename);
};

bool isValidDate(const std::string& date);

#endif // BITCOINEXCHANGE_HPP
