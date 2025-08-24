/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:16:17 by ouvled            #+#    #+#             */
/*   Updated: 2025/08/24 18:34:59 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Default constructor
Serializer::Serializer(void)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

// Copy constructor
Serializer::Serializer(const Serializer &other)
{
	std::cout << "Copy constructor called" << std::endl;
	(void) other;
	return ;
}

// Assignment operator overload
Serializer	&Serializer::operator=(const Serializer &other)
{
	std::cout << "Assignment operator called" << std::endl;
	(void) other;
	return (*this);
}

// Destructor
Serializer::~Serializer(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	uintptr_t	ret = reinterpret_cast<uintptr_t>(ptr);

	return (ret);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	Data	*retptr = reinterpret_cast<Data *>(raw);

	return (retptr);
}

