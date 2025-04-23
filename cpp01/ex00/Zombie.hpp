/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:24:42 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/04/03 13:25:05 by ouel-bou         ###   ########.fr       */
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
    void announce( void );
};

Zombie *newZombie( std::string name );
void    randomChump( std::string name );

