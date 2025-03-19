/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:20:08 by codespace         #+#    #+#             */
/*   Updated: 2025/03/19 07:01:19 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <iostream>
#include <iomanip>
#include <stdlib.h>


PhoneBook::PhoneBook(void) {
    
    this->index = 0;
    return ;
    
}

int PhoneBook::getIndex(void) const {
    
    return (this->index);
    
}

void    PhoneBook::incrementSize(void) {
    
    this->index++;
    return;

}

void    PhoneBook::addContact(void) {
    
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

void    PhoneBook::searchContact(void) {
    std::string index;
    
    if (this->list[0].getFirstName() == "N/A") {
        std::cout << "Phonebook is empty, add a new contact using the ADD command" << std::endl;
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
            std::cout << std::endl;
        }
    }
    std::cout << "Enter contact's ID for more information: ";
    getline(std::cin, index);
    while ((atoi(index.c_str()) < 1 || atoi(index.c_str()) > 8) || this->list[atoi(index.c_str()) - 1].getFirstName() == "N/A") {
        if (atoi(index.c_str()) < 1 || atoi(index.c_str()) > 8)
            std::cout << "IDs range is from 1 to 8." << std::endl;
        else
            std::cout << "Contact is empty." << std::endl;
        std::cout << "Enter contact's ID for more information: ";
        getline(std::cin, index);
    }
    std::cout << "First name     : " << this->list[atoi(index.c_str()) - 1].getFirstName() << std::endl;
    std::cout << "Last name      : " << this->list[atoi(index.c_str()) - 1].getLastName() << std::endl;
    std::cout << "Nickname       : " << this->list[atoi(index.c_str()) - 1].getNickName() << std::endl;
    std::cout << "Number         : " << this->list[atoi(index.c_str()) - 1].getNum() << std::endl;
    std::cout << "Darkest Secret : " << this->list[atoi(index.c_str()) - 1].getSecret() << std::endl;
    return ;
}
