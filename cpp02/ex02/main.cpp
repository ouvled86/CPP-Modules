/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 22:17:46 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/05/13 11:51:24 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed	a;
	Fixed	b( Fixed(1.245f) + Fixed(1) );

	std::cout << a << '\n';
	std::cout << ++a << '\n';
	std::cout << a++ << '\n';
	std::cout << a << '\n';
	// std::cout << a << '\n';
	// std::cout << "a raw bits: " << a.getRawBits() << '\n';
	// std::cout << "b raw bits: " << b.getRawBits() << '\n';
	// Fixed c(b + 2);
	// std::cout << "c raw bits: " << c.getRawBits() << '\n';
	// std::cout << c << '\n';

	// std::cout << Fixed::min( a, b ) << '\n';
	
	return 0;
}
