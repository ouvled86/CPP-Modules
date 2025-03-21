/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:19:54 by codespace         #+#    #+#             */
/*   Updated: 2025/03/21 02:21:37 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

int main()
{
	PhoneBook	book;
	std::string	buff;
	
	buff = "EMPTY";
	while (!std::cin.eof())
	{
		std::cout << "Enter a command: ";
		getline(std::cin, buff);
		if (buff.empty())
			std::cout << "Unrecognized command. use ADD, SEARCH or EXIT" << std::endl;
		if (buff == "ADD")
			book.addContact();
		else if (buff == "SEARCH")
			book.searchContact();
		else if (buff == "EXIT")
			exit(0);
	}
}
