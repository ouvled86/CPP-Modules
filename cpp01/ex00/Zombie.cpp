/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:28:59 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/05/10 11:41:15 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void ) {
	this->name = "UNNAMED ZOMBIE";
	return ;
}

Zombie::Zombie( std::string zName ) : name(zName) {
	return ;
}

Zombie::~Zombie( void ) {
	std::cout << this->name << " was destroyed." << '\n';
}

void	Zombie::announce( void ) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << '\n';
}

