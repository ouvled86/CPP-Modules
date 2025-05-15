/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:20:08 by codespace         #+#    #+#             */
/*   Updated: 2025/05/08 13:38:43 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) {
	this->index = 0;
	return ;
}

int	PhoneBook::getIndex(void) const {
	return (this->index);
}

void	PhoneBook::incrementSize(void) {
	this->index++;
	return;
}

void	PhoneBook::addContact(void) {
	t_info info;

	get_str(info.fname, "First name");
	get_str(info.lname, "Last name");
	get_str(info.nname, "Nickname");
	get_str(info.num, "Number");
	get_str(info.secret, "Darkest secret");
	if (getIndex() == 8)
		this->index = 0;
	this->list[this->index] = Contact( info );
	incrementSize();
}

void	PhoneBook::searchContact(void) {
	std::string buff;
	
	if (this->list[0].getFirstName() == "N/A") {
		std::cout << "Phonebook is empty, add a new contact using the ADD command" << '\n';
		return ;
	}
	for (int i = 0; i < 8; i++) {
		if (this->list[i].getFirstName() != "N/A") {
			std::cout << std::right << i + 1;
			std::cout << "|";
			std::cout << std::right << std::setw(10) << resizeString(this->list[i].getFirstName());
			std::cout << "|";
			std::cout << std::right << std::setw(10) << resizeString(this->list[i].getLastName());
			std::cout << "|";
			std::cout << std::right << std::setw(10) << resizeString(this->list[i].getNickName());
			std::cout << '\n';
		}
	}
	std::cout << "Enter contact's ID for more information: ";
	if (!std::getline(std::cin, buff)) {
		if (buff.empty()) {
			std::cout << '\n' << "Input error or EOF detected. Exiting search." << '\n';
			return;
		}
	}
	int index = buff[0] - '0';
	while (std::cin.eof() || buff.length() > 1 || (index < 1 || index > 8) || this->list[index - 1].getFirstName() == "N/A") {
		if (buff.length() > 1 || index < 1 || index > 8)
			std::cout << "IDs range is from 1 to 8." << '\n';
		else if (this->list[index - 1].getFirstName() == "N/A")
			std::cout << "Contact is empty." << '\n';
		std::cout << "Enter contact's ID for more information: ";
		std::getline(std::cin, buff);
		if (std::cin.eof()) {
				std::cout << '\n' << "Input error or EOF detected. Exiting search." << '\n';
				exit (1);
		}
		index = buff[0] - '0';
	}
	std::cout << "First name    : " << this->list[index - 1].getFirstName() << '\n';
	std::cout << "Last name     : " << this->list[index - 1].getLastName() << '\n';
	std::cout << "Nickname      : " << this->list[index - 1].getNickName() << '\n';
	std::cout << "Number        : " << this->list[index - 1].getNum() << '\n';
	std::cout << "Darkest Secret: " << this->list[index - 1].getSecret() << '\n';
	return ;
}
