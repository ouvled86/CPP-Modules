/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.utils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 19:54:52 by codespace         #+#    #+#             */
/*   Updated: 2025/03/19 07:06:46 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

bool    allSpaces(std::string buff)
{
    for (int i = 0; i < buff.length(); i++)
    {
        if(!isspace(buff[i]))
            return (false);
    }
    return (true);
}

void    get_str(std::string &buff, std::string str)
{
    std::cout << "Please enter contact's " << str << ": ";
    getline(std::cin, buff);
    while (buff.empty() || allSpaces(buff))
    {
        std::cout << str << " should not be empty." << std::endl << "Please enter contact's " << str << ": ";
        getline(std::cin, buff);
    }
}

std::string resizeString(std::string s)
{
    if(s.length() > 10)
        return (s.substr(0,9) += ".");
    return (s);
}
