/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:55:43 by ouvled            #+#    #+#             */
/*   Updated: 2025/09/09 19:49:04 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Error: bad usage. (./btc \"<FILE_NAME>\") " << std::endl;
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
		return 200;
	}

	BitcoinExchange	btc(data, input);
	btc.printData();

	// std::map<std::string, float> test = parseInput(input);
	
	return 0;
}