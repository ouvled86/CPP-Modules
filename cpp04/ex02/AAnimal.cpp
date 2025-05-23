/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:44:42 by ouvled            #+#    #+#             */
/*   Updated: 2025/05/21 11:44:43 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Default constructor
Animal::Animal(void)
{
	std::cout << "Animal's default constructor called" << std::endl;
	this->type = "Unknown";
	return ;
}

// Copy constructor
Animal::Animal(const Animal &other)
{
	std::cout << "Animal's copy constructor called" << std::endl;
	this->type = other.type;
	return ;
}

// Assignment operator overload
Animal	&Animal::operator=(const Animal &other)
{
	std::cout << "Animal's assignment operator called" << std::endl;
	this->type = other.type;
	return (*this);
}

// Destructor
Animal::~Animal(void)
{
	std::cout << "Animal's destructor called" << std::endl;
	return ;
}

