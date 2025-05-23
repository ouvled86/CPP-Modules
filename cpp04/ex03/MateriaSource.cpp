/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:12:06 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/05/23 14:12:07 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Default constructor
MateriaSource::MateriaSource(void)
{
	// std::cout << "MateriaSource's default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->Srcs[i] = NULL;
	return ;
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource &other)
{
	// std::cout << "MateriaSource's copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->Srcs[i] = other.Srcs[i]->clone();
	return ;
}

// Assignment operator overload
MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	// std::cout << "MateriaSource's assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->Srcs[i])
				delete this->Srcs[i];
			if (other.Srcs[i])
				this->Srcs[i] = other.Srcs[i]->clone();
		}
	}
	return (*this);
}

// Destructor
MateriaSource::~MateriaSource(void)
{
	// std::cout << "MateriaSource's destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->Srcs[i])
			delete this->Srcs[i];
	}
	return ;
}

void	MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->Srcs[i]) {
			this->Srcs[i] = m->clone();
			break ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	AMateria*	ret = NULL;

	for (int i = 0; i < 4; i++)
	{
		if (this->Srcs[i] && this->Srcs[i]->getType() == type)
		{
			ret = this->Srcs[i]->clone();
			break;
		}
	}
	return (ret);
}
