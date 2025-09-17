/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 16:31:30 by ouvled            #+#    #+#             */
/*   Updated: 2025/09/14 19:01:34 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: bad usage. (./PmergeMe <POSITIVE_INT_SEQUENCE>)" << std::endl;
		return 100;
	}
	std::string	input = mergeInput(av, ac);
	PmergeMe	PM(input);
	PM.sortDeque();
	// PM.sortDeque();
	// PM.printInfo();
}