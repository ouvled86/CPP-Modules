/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 06:43:59 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/04/26 23:37:41 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << '\n';
	this->Value = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << '\n';
	this->Value = value << this->Bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << '\n';
	this->Value = roundf(value * (1 << this->Bits));
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

Fixed&	Fixed::operator+(const Fixed& original)
{

	this->Value = this->Value + original.getRawBits();
	return (*this);
	
}

Fixed&	Fixed::operator-(const Fixed& original)
{
	
	Fixed	*ret;
	
	ret->setRawBits(this->Value - original.getRawBits());
	return (*ret);
	
}

Fixed&	Fixed::operator*(const Fixed& original)
{
	
	Fixed	*ret;
	
	ret->setRawBits(this->Value * original.getRawBits());
	return (*ret);
	
}

Fixed&	Fixed::operator/(const Fixed& original)
{
		
	Fixed	*ret;
	
	ret->setRawBits(this->Value / original.getRawBits());
	return (*ret);

}

bool	Fixed::operator>(const Fixed& original)
{

	if (this->getRawBits() > original.getRawBits())
		return (true);
	return (false);

}

bool	Fixed::operator<(const Fixed& original)
{

	if (this->getRawBits() < original.getRawBits())
		return (true);
	return (false);

}

bool	Fixed::operator>=(const Fixed& original)
{
	
	if (this->getRawBits() >= original.getRawBits())
		return (true);
	return (false);
	
}
bool	Fixed::operator<=(const Fixed& original)
{
	
	if (this->getRawBits() <= original.getRawBits())
		return (true);
	return (false);
	
}

bool	Fixed::operator==(const Fixed& original)
{
	
	if (this->getRawBits() == original.getRawBits())
		return (true);
	return (false);
	
}

bool	Fixed::operator!=(const Fixed& original)
{
	
	if (this->getRawBits() != original.getRawBits())
		return (true);
	return (false);
	
}

Fixed&	Fixed::operator++(void)
{
	
	this->Value++;
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	
	this->Value--;
	return (*this);
	
}

Fixed	Fixed::operator++(const int original)
{
	
	Fixed	copy(*this);
	this->Value++;
	return (copy);
	
}

Fixed	Fixed::operator--(const int original)
{
	
	int	copy = this->Value;
	this->Value--;
	return (copy);
	
}

Fixed&	Fixed::min(Fixed &first, Fixed &second)
{
	
	if (first.getRawBits() > second.getRawBits())
		return (second);
	return (first);

}

Fixed&	Fixed::max(Fixed &first, Fixed &second)
{
	
	if (first.getRawBits() > second.getRawBits())
		return (first);
	return (second);
	
	
}

const Fixed&	Fixed::min(const Fixed &first, const Fixed &second)
{
	Fixed firstCopy(first);
	Fixed secondCopy(second);

	if (first.getRawBits() > second.getRawBits())
		return (second);
	return (first);

}

const Fixed&	Fixed::max(const Fixed &first, const Fixed &second)
{
	
	Fixed firstCopy(first);
	Fixed secondCopy(second);
	
	if (first.getRawBits() > second.getRawBits())
		return (first);
	return (second);
	
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << '\n';
}

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << '\n';
	return this->Value;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << '\n';
	this->Value = raw;
}

float	Fixed::toFloat( void ) const
{
	float	ret = this->Value / (float)(1 << this->Bits);
	return ret;
}

int	Fixed::toInt( void ) const
{
	return this->Value >> this->Bits;
}

std::ostream&	operator<<(std::ostream& cout, Fixed& original)
{
	cout << original.toFloat();
	return cout;	
}

std::ostream&	operator<<(std::ostream& cout, const Fixed& original)
{
	cout << original.toFloat();
	return cout;	
}
