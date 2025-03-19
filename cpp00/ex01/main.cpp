/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:19:54 by codespace         #+#    #+#             */
/*   Updated: 2025/03/19 06:26:26 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

int main()
{
	PhoneBook	book;
	std::string	buff;
	
	while (86)
	{
		std::cout << "Enter a command: ";
		getline(std::cin, buff);
		if (buff == "ADD")
			book.addContact();
		else if (buff == "SEARCH")
			book.searchContact();
		else if (buff == "EXIT")
			exit(0);
		else
			std::cout << "Unrecognized command. use ADD, SEARCH or EXIT" << std::endl;
			
	}
}
