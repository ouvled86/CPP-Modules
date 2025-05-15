/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:30:29 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/05/15 12:32:26 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed {
private:
	int					Value;
	static const int	Bits;

public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& original);
	~Fixed();
	Fixed&				operator=(const Fixed& original);
	Fixed				operator+(const Fixed& original);
	Fixed				operator-(const Fixed& original);
	Fixed				operator*(const Fixed& original);
	Fixed				operator/(const Fixed& original);
	bool				operator>(const Fixed& original);
	bool				operator<(const Fixed& original);
	bool				operator>=(const Fixed& original);
	bool				operator<=(const Fixed& original);
	bool				operator==(const Fixed& original);
	bool				operator!=(const Fixed& original);
	static Fixed&		min(Fixed &first, Fixed &second);
	static Fixed&		max(Fixed &first, Fixed &second);
	static const Fixed&	min(const Fixed &first, const Fixed &second);
	static const Fixed&	max(const Fixed &first, const Fixed &second);
	Fixed&				operator++(void);
	Fixed&				operator--(void);
	Fixed				operator++(int);
	Fixed				operator--(int);
	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	float				toFloat(void) const;
	int					toInt( void ) const;
};

std::ostream&		operator<<(std::ostream& coutref, Fixed& original);
std::ostream&		operator<<(std::ostream& coutref, const Fixed& original);
