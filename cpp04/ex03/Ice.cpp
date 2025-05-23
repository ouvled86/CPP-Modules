/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:11:52 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/05/23 21:17:04 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// Default constructor
Ice::Ice(void) : AMateria("ice")
{
	// std::cout << "Ice's default constructor called" << std::endl;
	return ;
}

// Copy constructor
Ice::Ice(const Ice &other) : AMateria("ice")
{
	// std::cout << "Ice's copy constructor called" << std::endl;
	(void) other;
	return ;
}

// Assignment operator overload
Ice	&Ice::operator=(const Ice &other)
{
	// std::cout << "Ice's assignment operator called" << std::endl;
	(void) other;
	return (*this);
}

// Destructor
Ice::~Ice(void)
{
	// std::cout << "Ice's destructor called" << std::endl;
	return ;
}

AMateria	*Ice::clone() const
{
	AMateria	*ret = new Ice();
	return (ret);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
