/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:44:50 by ouvled            #+#    #+#             */
/*   Updated: 2025/05/21 11:44:51 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Default constructor
Cat::Cat(void)
{
	std::cout << "Cat's default constructor called" << std::endl;
	this->type = "Cat";
	return ;
}

// Copy constructor
Cat::Cat(const Cat &other)
{
	std::cout << "Cat's copy constructor called" << std::endl;
	this->type = other.type;
	return ;
}

// Assignment operator overload
Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Cat's assignment operator called" << std::endl;
	this->type = other.type;
	return (*this);
}

// Destructor
Cat::~Cat(void)
{
	std::cout << "Cat's destructor called" << std::endl;
	return ;
}

void	Cat::makeSound()
{
	std::cout << "Cat's makeSound called" << std::endl;
	std::cout << "MEOW!" << std::endl;

}
