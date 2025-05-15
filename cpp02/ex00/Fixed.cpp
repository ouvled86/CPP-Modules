/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 06:43:59 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/05/13 11:08:35 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::Bits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << '\n';
	this->Value = 0;
}

Fixed::Fixed(const Fixed& original)
{
	std::cout << "Copy constructor called" << '\n';
	this->Value = original.getRawBits();
}

Fixed&	Fixed::operator=(const Fixed& original)
{
	std::cout << "Copy assignment operator called" << '\n';
	if (this != &original)
		this->Value = original.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << '\n';
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << '\n';
	return this->Value;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << '\n';
	this->Value = raw;
}
