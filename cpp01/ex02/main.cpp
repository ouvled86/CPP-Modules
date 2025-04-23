/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:12:02 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/04/03 14:19:15 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main( void ) {

    std::string s = "HI THIS IS BRAIN";
    std::string *stringPTR = &s;
    std::string &stringREF = s;

    std::cout << "The memory address of s is: " << &s << std::endl;
    std::cout << "The memory address held by stringPTR is: " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF is: " << &stringREF << std::endl;
    std::cout << "The value of s: " << s << std::endl;
    std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;

}

