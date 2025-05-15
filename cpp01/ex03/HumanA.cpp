/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:06:08 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/05/10 13:50:12 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string humanName, Weapon& humanWeapon ) : name(humanName), wpn(humanWeapon) {
	return ;
}

HumanA::~HumanA( void ) {
	return ;
}

void	HumanA::attack( void ) const {
	std::cout << name << " attacks with their " << this->wpn.getType() << '.' << '\n';
}
