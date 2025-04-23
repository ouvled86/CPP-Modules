/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:00:39 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/04/03 15:41:08 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"
#include <string>
#include <iostream>

class   HumanB {

private:
    std::string name;
    Weapon      *wpn;

public:
    HumanB( void );
    HumanB( std::string humanName );
    ~HumanB( void );
    void    attack( void ) const;
    void    setWeapon( Weapon newWpn );

};
