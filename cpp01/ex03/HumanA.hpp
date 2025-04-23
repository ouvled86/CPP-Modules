/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:53:05 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/04/03 15:34:40 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"
#include <string>
#include <iostream>

class   HumanA {

private:
    std::string name;
    Weapon      &wpn;

public:
    HumanA( std::string humanName, Weapon humanWeapon);
    ~HumanA( void );
    void    attack( void ) const;

};
