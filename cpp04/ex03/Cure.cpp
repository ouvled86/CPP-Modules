/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:11:47 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/05/23 19:53:29 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// Default constructor
Cure::Cure(void) : AMateria("cure")
{
	// std::cout << "Cure's default constructor called" << std::endl;
	return ;
}

// Copy constructor
Cure::Cure(const Cure &other) : AMateria("cure")
{
	// std::cout << "Cure's copy constructor called" << std::endl;
	(void) other;
	return ;
}

// Assignment operator overload
Cure	&Cure::operator=(const Cure &other)
{
	// std::cout << "Cure's assignment operator called" << std::endl;
	(void) other;
	return (*this);
}

// Destructor
Cure::~Cure(void)
{
	// std::cout << "Cure's destructor called" << std::endl;
	return ;
}

AMateria	*Cure::clone() const
{
	Cure *ret = new Cure();
	return (ret);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
