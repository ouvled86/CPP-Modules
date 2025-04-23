/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:26:57 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/04/03 14:05:40 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie  *zombieHorde( int N, std::string name) {

    if ( N < 0 ) {
        std::cerr << "N should be positive, dummy" << std::endl;
        return NULL;
    }
    Zombie   *zombies = new Zombie[N];
    for ( int i = 0; i < N; i++ )
        zombies[i].nameSetter(name);
    return zombies;

}
