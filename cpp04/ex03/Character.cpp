/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:11:40 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/05/23 22:20:25 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"

// Default constructor
Character::Character(void) : Name("N/A")
{
	// std::cout << "Character's default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->Slots[i] = NULL;
	col	= NULL;
	return ;
}

Character::Character(std::string const& name) : Name(name)
{
	// std::cout << "Character's default constructor called" << std::endl;
	col	= NULL;
	for (int i = 0; i < 4; i++)
		this->Slots[i] = NULL;
	return ;
}

// Copy constructor
Character::Character(const Character &other) : ICharacter(), Name(other.Name)
{
    col = NULL;
    for (int i = 0; i < 4; i++)
    {
        this->Slots[i] = NULL;
        if (other.Slots[i])
			this->Slots[i] = other.Slots[i]->clone();
    }
    return;
}

// Assignment operator overload
Character	&Character::operator=(const Character &other)
{
	// std::cout << "Character's assignment operator called" << std::endl;
	if (this != &other)
	{
	    col	= NULL;
		this->Name = other.Name;
		for (int i = 0; i < 4; i++)
		{
			if (this->Slots[i])
			{
				delete this->Slots[i];
				this->Slots[i] = NULL;
			}
            else
                this->Slots[i] = NULL;
			if (other.Slots[i])
				this->Slots[i] = other.Slots[i]->clone();
		}
	}
	return (*this);
}

// Destructor
Character::~Character(void)
{
	// std::cout << "Character's destructor called" << std::endl;
	this->freeMemory();
	return ;
}

std::string const&	Character::getName() const
{
	return (this->Name);
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->Slots[i])
		{
			this->Slots[i] = m;
			break ;
		}
	}
}

void	Character::unequip(int idx)
{
	if ((idx >= 0 && idx <= 3) && this->Slots[idx])
	{
		this->col = this->insertNode(this->Slots[idx]);
		this->Slots[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if ((idx >= 0 && idx <= 3) && this->Slots[idx])
		this->Slots[idx]->use(target);
}

Node	*Character::insertNode(AMateria *m)
{
	Node	*tmp = this->col;

    if (!this->col)
    {
        this->col = new Node;
        this->col->m = m;
        this->col->next = NULL;
        return this->col;
    }
    while (this->col->next)
       this->col = this->col->next;
    this->col->next = new Node;
	this->col->next->m = m;
    this->col->next->next = NULL;
    return (tmp);
}

void	Character::freeMemory(void)
{
	for (int i = 0; i < 4; i++)
	{
       if (this->Slots[i])
           delete this->Slots[i];
	}
	Node	*tmp;
	while(this->col)
	{
		delete this->col->m;
		tmp = this->col;
		this->col = this->col->next;
		delete tmp;
	}
}

