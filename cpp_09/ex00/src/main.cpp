#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	
	std::string database;
	std::string input;
	switch (argc) {
		case 2:
			database = "cpp_09/data.csv";
			input = argv[1];
			break;
		case 3:
			database = argv[1];
			input = argv[2];
			break;
		default:
			std::cerr << "Usage:\t./btc <historical_data.csv> <input.txt>" << std::endl;
			std::cerr << "\t./btc <input.txt>" << std::endl;
			return 1;
	}

	BitcoinExchange btc;
	btc.loadHistoricalData(database);
	btc.processInputFile(input);

	return 0;
}
