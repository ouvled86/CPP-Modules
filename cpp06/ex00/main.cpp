/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 20:56:08 by ouvled            #+#    #+#             */
/*   Updated: 2025/08/22 16:31:12 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Only 1 argument is required to run this program!" << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
}
