/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:28:59 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/04/03 14:08:10 by ouel-bou         ###   ########.fr       */
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

    std::cout << this->name << " was destroyed." << std::endl;

}

void    Zombie::nameSetter( std::string zName ) {

    this->name = zName;
    return ;

}

void    Zombie::announce( void ) {

    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;

}

