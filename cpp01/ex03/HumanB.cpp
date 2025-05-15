/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:25:15 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/05/10 13:49:56 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( void ) {	
	this->wpn = NULL;
	return ;
}

HumanB::HumanB( std::string humanName ) : name(humanName) {
	this->wpn = NULL;
	return ;
}

HumanB::~HumanB( void ) {
	return ;
}

void	HumanB::attack( void ) const {
	std::cout << name << " attacks with their ";
	if (this->wpn)
		std::cout << this->wpn->getType() << '.' << '\n';
	else
		std::cout << "hands." << '\n';
}

void	HumanB::setWeapon( Weapon *newWpn ) {
	this->wpn = newWpn;
}
