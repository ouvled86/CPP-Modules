/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 07:35:01 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/05/15 12:12:08 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << '\n';
	std::cout << "b is " << b << '\n';
	std::cout << "c is " << c << '\n';
	std::cout << "d is " << d << '\n';
	std::cout << "a is " << a.toInt() << " as integer" << '\n';
	std::cout << "b is " << b.toInt() << " as integer" << '\n';
	std::cout << "c is " << c.toInt() << " as integer" << '\n';
	std::cout << "d is " << d.toInt() << " as integer" << '\n';

	return 0;
}