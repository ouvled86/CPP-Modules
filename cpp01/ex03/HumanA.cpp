/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:06:08 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/04/03 15:34:53 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string humanName, Weapon humanWeapon ) : name(humanName), wpn(humanWeapon) {

    return ;

}

HumanA::~HumanA( void ) {

    return ;

}

void    HumanA::attack( void ) const {

    std::cout << name << " attacks with their " << this->wpn.getType() << std::endl;

}

