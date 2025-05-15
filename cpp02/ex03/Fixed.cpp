/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 06:43:59 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/05/15 12:32:28 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::Bits = 8;

Fixed::Fixed()
{
	this->Value = 0;
	return ;
}

Fixed::Fixed(const int value)
{
	this->Value = value << this->Bits;
	return ;
}

Fixed::Fixed(const float value)
{
	this->Value = roundf(value * (1 << this->Bits));
	return ;
}

Fixed::Fixed(const Fixed& original)
{
	this->Value = original.getRawBits();
	return ;
}

Fixed&	Fixed::operator=(const Fixed& original)
{
	if (this != &original)
		this->Value = original.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(const Fixed& original)
{
	Fixed	ret;

	ret.Value = this->Value + original.Value;
	return (ret);
}

Fixed	Fixed::operator-(const Fixed& original)
{
	Fixed	ret;

	ret.Value = this->Value - original.Value;
	return (ret);
}

Fixed	Fixed::operator*(const Fixed& original)
{
	Fixed	ret;

	ret.Value = this->Value * original.Value;
	return (ret);
}

Fixed	Fixed::operator/(const Fixed& original)
{
	Fixed	ret;

	ret.Value = this->Value / original.Value;
	return (ret);
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

Fixed	Fixed::operator++(int)
{
	Fixed	copy(*this);
	this->Value++;
	return (copy);
}

Fixed	Fixed::operator--(int)
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
	return ;
}

int	Fixed::getRawBits(void) const
{
	return this->Value;
}

void	Fixed::setRawBits(int const raw)
{
	this->Value = raw;
	return ;
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

std::ostream&	operator<<(std::ostream& coutref, Fixed& original)
{
	coutref << original.toFloat();
	return coutref;
}

std::ostream&	operator<<(std::ostream& coutref, const Fixed& original)
{
	coutref << original.toFloat();
	return coutref;
}
