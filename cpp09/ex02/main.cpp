/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 16:31:30 by ouvled            #+#    #+#             */
/*   Updated: 2025/09/17 20:45:59 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: bad usage. (./PmergeMe <POSITIVE_INT_SEQUENCE>)" << std::endl;
		return 100;
	}
	std::string	input = mergeInput(av, ac);
	PmergeMe	PM(input);
	PM.printInfo();
}