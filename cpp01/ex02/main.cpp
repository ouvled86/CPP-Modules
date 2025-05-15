/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:12:02 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/05/10 12:03:30 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main( void ) {
	std::string s = "HI THIS IS BRAIN";
	std::string *stringPTR = &s;
	std::string &stringREF = s;

	std::cout << "The memory address of s is             : " << &s << '\n';
	std::cout << "The memory address held by stringPTR is: " << stringPTR << '\n';
	std::cout << "The memory address held by stringREF is: " << &stringREF << '\n';
	std::cout << '\n';
	std::cout << "The value of s                         : " << s << '\n';
	std::cout << "The value pointed to by stringPTR      : " << *stringPTR << '\n';
	std::cout << "The value pointed to by stringREF      : " << stringREF << '\n';
}

