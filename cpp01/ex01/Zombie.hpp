/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:24:42 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/04/03 14:00:18 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Zombie {

private:
    std::string name;

public:
    Zombie( void );
    Zombie( std::string zName );
    ~Zombie( void );
    void    nameSetter( std::string zName );
    void    announce( void );
};

Zombie *zombieHorde( int N, std::string name );

