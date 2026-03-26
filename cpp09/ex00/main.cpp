#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>

int main(int ac, char **av)
{
	if (ac < 2) {
		std::cerr << "Error: bad usage. (./btc \"<FILE_NAME>\")" << std::endl;
		return 100;
	}

	std::ifstream	data("data.csv");
	if ( !data ) {
		std::cerr << "Error: couldn't open data file. " << std::endl;
		return 200;
	}

	std::ifstream	input(av[1]);
	if ( !input ) {
		std::cerr << "Error: couldn't open input file. " << std::endl;
		return 201;
	}

	BitcoinExchange	btc(data, input);
	btc.printData();

	return 0;
}