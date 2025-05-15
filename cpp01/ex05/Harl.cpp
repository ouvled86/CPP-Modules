/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:04:55 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/05/12 10:11:02 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>

void	Harl::debug( void ) {
	std::cout << "[ DEBUG ]" << '\n';
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << '\n';
	std::cout << "I really do!" << '\n';
	return ;
}

void	Harl::info( void ) {
	std::cout << "[ INFO ]" << '\n';
	std::cout << "I cannot believe adding extra bacon costs more money." << '\n';
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << '\n';
	return ;
}

void	Harl::warning( void ) {
	std::cout << "[ WARNING ]" << '\n';
	std::cout << "I think I deserve to have some extra bacon for free." << '\n';
	std::cout << "I've been coming for years, whereas you started working here just last month." << '\n';
	return ;
}

void	Harl::error( void ) {
	std::cout << "[ ERROR ]" << '\n';
	std::cout << "This is unacceptable! I want to speak to the manager now." << '\n';
	return ;
}

void	Harl::complain( std::string level ) {
	void	( Harl::*funcs[4] )( void ) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for ( int i = 0; i < 4; i++ ) {
		if ( levels[i] == level ) {
			(this->*funcs[i])();
			std::cout << '\n';
		}
	}
}
