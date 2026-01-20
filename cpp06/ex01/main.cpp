/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:16:14 by ouvled            #+#    #+#             */
/*   Updated: 2026/01/20 21:49:34 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data		*meow = new Data;
	uintptr_t	holder;

	meow->value = 10;
	holder = Serializer::serialize(meow);
	std::cout << "Meow's address: " << meow << " - holder's value: " << holder << std::endl;
	std::cout << "Deserializing: " << Serializer::deserialize(holder) << ", value inside Data: " << Serializer::deserialize(holder)->value << std::endl;
	delete meow;
	return 0;
}