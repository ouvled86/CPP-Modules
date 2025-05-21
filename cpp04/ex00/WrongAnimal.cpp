/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:45:07 by ouvled            #+#    #+#             */
/*   Updated: 2025/05/21 11:45:08 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Default constructor
WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal's default constructor called" << std::endl;
	this->type = "Unknown";
	return ;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "WrongAnimal's copy constructor called" << std::endl;
	this->type = other.type;
	return ;
}

// Assignment operator overload
WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal's assignment operator called" << std::endl;
	this->type = other.type;
	return (*this);
}

// Destructor
WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal's destructor called" << std::endl;
	return ;
}

void	WrongAnimal::makeSound()
{
	std::cout << "WrongAnimal's makeSound called" << std::endl;
	std::cout << "Apah apah" << std::endl;

}
