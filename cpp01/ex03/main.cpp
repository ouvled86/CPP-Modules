/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:12:58 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/04/03 15:41:39 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main() {

    Weapon  knife("Military Knife");
    HumanA  meowski("Meowski", knife);
    HumanB  meower("Meower");

    meowski.attack();
    meower.attack();

}
