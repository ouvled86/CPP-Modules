/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:45:15 by ouvled            #+#    #+#             */
/*   Updated: 2025/05/21 11:45:16 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Default constructor
WrongCat::WrongCat(void)
{
	std::cout << "WrongCat's default constructor called" << std::endl;
	this->type = "WrongCat";
	return ;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat &other)
{
	std::cout << "WrongCat's copy constructor called" << std::endl;
	this->type = other.type;
	return ;
}

// Assignment operator overload
WrongCat	&WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat's assignment operator called" << std::endl;
	this->type = other.type;
	return (*this);
}

// Destructor
WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat's destructor called" << std::endl;
	return ;
}

void	WrongCat::makeSound()
{
	std::cout << "WrongCat's makeSound called" << std::endl;
	std::cout << "MEOW!" << std::endl;

}
