/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:16:14 by ouvled            #+#    #+#             */
/*   Updated: 2025/08/24 18:38:02 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data		meow;
	uintptr_t	holder;

	meow.value = 10;
	holder = Serializer::serialize(&meow);
	std::cout << "Meow's address: " << &meow << " - holder's value: " << holder << std::endl;
	std::cout << "Deserializing: " << Serializer::deserialize(holder) << std::endl;
	return 0;
}