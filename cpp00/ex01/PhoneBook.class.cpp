/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:20:08 by codespace         #+#    #+#             */
/*   Updated: 2025/03/17 20:38:54 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <iostream>
#include <iomanip>

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
    std::cout << info.fname << info.lname << info.nname << info.num << info.secret << std::endl;
}

void    PhoneBook::searchContact(void) {
    
    for (int i = 0; i < 8; i++) {
        if (this->list[i].getFirstName() != "N/A") {
            std::cout << std::right << i;
            std::cout << "|";
            std::cout << std::right << std::setw(10) << this->list[i].getFirstName();
            std::cout << "|";
            std::cout << std::right << std::setw(10) << this->list[i].getLastName();
            std::cout << "|";
            std::cout << std::right << std::setw(10) << this->list[i].getNickName();
            std::cout << std::endl;
        }
    }
    
}
