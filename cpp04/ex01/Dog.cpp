/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:44:55 by ouvled            #+#    #+#             */
/*   Updated: 2025/05/21 13:07:38 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Default constructor
Dog::Dog(void)
{
	std::cout << "Dog's default constructor called" << std::endl;
	this->brain = new Brain();
	this->type = "Dog";
	return ;
}

// Copy constructor
Dog::Dog(const Dog &other) : Animal()
{
	std::cout << "Dog's copy constructor called" << std::endl;
	int	size = other.brain->getSize();
	this->type = other.type;
	this->brain = new Brain();
	for (int i = 0; i < size; i++)
		this->brain->addIdea(other.brain->getIdea(i));
	return ;
}

// Assignment operator overload
Dog	&Dog::operator=(const Dog &other)
{
	std::cout << "Dog's assignment operator called" << std::endl;
	if (this != &other)
	{
		int	size = other.brain->getSize();
		this->type = other.type;
		this->brain = new Brain();
		for (int i = 0; i < size; i++)
			this->brain->addIdea(other.brain->getIdea(i));
	}
	return (*this);
}

// Destructor
Dog::~Dog(void)
{
	std::cout << "Dog's destructor called" << std::endl;
	delete this->brain;
	return ;
}

void	Dog::makeSound()
{
	std::cout << "Dog's makeSound called" << std::endl;
	std::cout << "WOOF!" << std::endl;

}
