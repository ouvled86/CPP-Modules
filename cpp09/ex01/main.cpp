#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: bad usage. (./RPN \"<RPN_EXPRESSION>\")" << std::endl;
		return 100;
	}

	std::string	input(av[1]);
	if (badInput(input))
	{
		std::cerr << "Error: bad input." << std::endl;
		return 200;
	}

	RPN	calculator(input);
	calculator.evaluate();
	calculator.printResult();
}
