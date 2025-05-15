/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:19:54 by codespace         #+#    #+#             */
/*   Updated: 2025/05/08 13:38:43 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

int main() {
	PhoneBook	book;
	std::string	buff;

	buff = "EMPTY";
	while (86) {
		std::cout << "Enter a command: ";
		std::getline(std::cin, buff);
		if (buff == "ADD")
			book.addContact();
		else if (buff == "SEARCH")
			book.searchContact();
		else if (buff == "EXIT")
			exit(0);
		else if (std::cin.eof()) {
			std::cout << "EOF Detected, exiting with error code: 1" << '\n';
			exit(1);
		}
		else
			std::cout << "Unrecognized command. use ADD, SEARCH or EXIT" << '\n';
	}
}
