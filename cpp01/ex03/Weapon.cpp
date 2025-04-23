/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:40:22 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/04/03 15:21:54 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

Weapon::Weapon( void ) {

    return ;

}

Weapon::Weapon ( const std::string& wName ) : type(wName) {

    return ;

}

Weapon::~Weapon ( void ) {

    return ;

}

const std::string&  Weapon::getType( void ) const {

    return this->type;

}

void    Weapon::setType( const std::string& newType ) {

    this->type = newType;
    return ;

}

