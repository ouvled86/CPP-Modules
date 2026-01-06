/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:10:27 by ouvled            #+#    #+#             */
/*   Updated: 2025/08/15 16:29:28 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void )
{
	Bureaucrat	B1("Meow King", 1);
	Bureaucrat	B2("Meow Boss", 5);
	Bureaucrat	B3("Stray Meow", 130);

	AForm		*F1 = new PresidentialPardonForm("Meowster");
	AForm		*F2 = new RobotomyRequestForm("Meowstang");
	AForm		*F3 = new ShrubberyCreationForm("Meowski");

	std::cout << "\n" << *F1 << *F2 << *F3 << std::endl;
	B1.signForm(*F1);
	B1.signForm(*F2);
	B1.signForm(*F3);
	B1.signForm(*F3);
	std::cout << std::endl;

	B3.executeForm(*F1);
	B2.executeForm(*F1);
	B2.executeForm(*F2);
	B2.executeForm(*F2);
	B2.executeForm(*F2);
	B2.executeForm(*F2);
	B3.executeForm(*F3);

	std::cout << "\n";

	delete F1;
	delete F2;
	delete F3;
}