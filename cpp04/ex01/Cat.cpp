/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:44:50 by ouvled            #+#    #+#             */
/*   Updated: 2025/05/21 13:14:15 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Default constructor
Cat::Cat(void)
{
	std::cout << "Cat's default constructor called" << std::endl;
	this->brain = new Brain();
	this->type = "Cat";
	return ;
}

// Copy constructor
Cat::Cat(const Cat &other) : Animal()
{
	std::cout << "Cat's copy constructor called" << std::endl;
	int	size = other.brain->getSize();
	this->type = other.type;
	this->brain = new Brain();
	for (int i = 0; i < size; i++)
		this->brain->addIdea(other.brain->getIdea(i));
	return ;
}

// Assignment operator overload
Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Cat's assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		delete this->brain;
		int	size = other.brain->getSize();
		this->brain = new Brain();
		for (int i = 0; i < size; i++)
			this->brain->addIdea(other.brain->getIdea(i));
	}
	return (*this);
}

// Destructor
Cat::~Cat(void)
{
	std::cout << "Cat's destructor called" << std::endl;
	delete this->brain;
	return ;
}

void	Cat::makeSound()
{
	std::cout << "Cat's makeSound called" << std::endl;
	std::cout << "MEOW!" << std::endl;

}
