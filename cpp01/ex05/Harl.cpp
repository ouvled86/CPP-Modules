/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:04:55 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/04/04 14:32:48 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>

void    Harl::debug( void ) {

    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
    std::cout << "I really do!" << std::endl;
    return ;

}

void    Harl::info( void ) {

    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
    return ;
  
}

void    Harl::warning( void ) {

    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I've been coming for years, whereas you started working here just last month." << std::endl;
    return ;
  
}

void    Harl::error( void ) {

    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    return ;
  
}

void    Harl::complain( std::string level ) {

    void    ( Harl::*funcs[4] )( void ) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error, };
    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR", };
    for ( int i = 0; i < 4; i++ ) {
        if ( levels[i] == level )
            (this->*funcs[i])();
    }

}
