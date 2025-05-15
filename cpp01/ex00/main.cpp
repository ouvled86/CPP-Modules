/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:42:24 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/05/10 11:42:21 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main ( void ) {
	Zombie *z = newZombie("Meowski");

	randomChump("Woofski");
	z->announce();
	delete z;
	return 0;
}
