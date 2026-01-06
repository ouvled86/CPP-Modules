/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:10:27 by ouvled            #+#    #+#             */
/*   Updated: 2025/12/29 15:37:41 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void )
{
	Bureaucrat B1;
	Bureaucrat B2("Miko", 130);
	Bureaucrat B3(B2);
	try {
		Bureaucrat B4("Meowster", 151);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "B1 name: " << B1.getName() << " B2 name: " << B2.getName() << " B3 name: " << B3.getName() << std::endl;
	std::cout << "B1 grade: " << B1.getGrade() << " B2 grade: " << B2.getGrade() << " B3 grade: " << B3.getGrade() << std::endl;
	B2.incrementGrade();
	std::cout << "B1 grade: " << B1.getGrade() << " B2 grade: " << B2.getGrade() << " B3 grade: " << B3.getGrade() << std::endl;
	std::cout << "\n" << B1 << "\n" << B2 << "\n" << B3 << "\n" << std::endl;
	try {
		B1.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}