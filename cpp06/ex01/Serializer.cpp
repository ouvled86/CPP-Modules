/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:16:17 by ouvled            #+#    #+#             */
/*   Updated: 2026/01/21 00:20:48 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
	return ;
}

Serializer::Serializer(const Serializer &other)
{
	(void) other;
	return ;
}

Serializer	&Serializer::operator=(const Serializer &other)
{
	(void) other;
	return (*this);
}

Serializer::~Serializer(void)
{
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

