/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:42:24 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/04/02 15:38:22 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main ( void ) {
    Zombie *z = newZombie("Meow");
    Zombie  z1;
    randomChump("Woof");
    z->announce();
    delete z;
    return 0;
}
