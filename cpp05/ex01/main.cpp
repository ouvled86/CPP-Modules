/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:10:27 by ouvled            #+#    #+#             */
/*   Updated: 2025/08/14 12:42:50 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{
	Bureaucrat	B1("Mista", 25);
	Bureaucrat	B2("Mikasa", 130);
	Form		F1("Purchase order", 25, 15);
	Form		F2("Travel Authorization", 140, 100);
	Form		F3(F1);
	// Form		F4("Broken Form", -1, 8686);
	std::cout << "\n" << F1 << F2 << std::endl;
	B1.signForm(F1);
	B2.signForm(F2);
	B2.signForm(F3);
	std::cout << "\n";
}