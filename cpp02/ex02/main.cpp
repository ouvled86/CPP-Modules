/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 22:17:46 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/04/27 13:38:30 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
    Fixed a;
    Fixed b( Fixed(1.245f) + Fixed(1) );
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << "a raw bits: " << a.getRawBits() << std::endl;
    std::cout << "b raw bits: " << b.getRawBits() << std::endl;
    Fixed c(b + 2);
    std::cout << "c raw bits: " << c.getRawBits() << std::endl;
    std::cout << c << std::endl;
    
    std::cout << Fixed::min( a, b ) << std::endl;
    
    return 0;
}
