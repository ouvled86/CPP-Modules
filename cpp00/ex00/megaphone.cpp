/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:24:46 by codespace         #+#    #+#             */
/*   Updated: 2025/03/07 18:21:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int	main(int ac, char **av)
{
	std::string	cStr;
	int			j;
	
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < ac; i++)
	{
		j = -1;
		while(av[i][++j])
			cStr += toupper(av[i][j]);
		if (!isspace(av[i][j - 1]) && i < ac - 1 && !isspace(av[i + 1][0]))
			cStr += ' ';
	}
	std::cout << cStr << std::endl;
}
