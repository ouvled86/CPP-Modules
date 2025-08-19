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
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void )
{
	Intern	ghost;
	AForm	*ghostsForm;
	Bureaucrat	MeowKing("Meowsta", 1);

	ghostsForm = ghost.makeForm("crip walk permission", "meowster");
	ghostsForm = ghost.makeForm("shrubbery creation", "meowster");

	MeowKing.signForm(*ghostsForm);
	MeowKing.executeForm(*ghostsForm);
	delete ghostsForm;
}