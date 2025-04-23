/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:25:15 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/04/03 15:40:57 by ouel-bou         ###   ########.fr       */
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

void    HumanB::attack( void ) const {

    std::cout << name << " attacks with their " << this->wpn->getType() << std::endl;

}

void    HumanB::setWeapon( Weapon newWpn ) {

    this->wpn = &newWpn;

}

