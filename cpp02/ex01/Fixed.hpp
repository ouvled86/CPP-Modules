/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:30:29 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/04/26 09:14:26 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed {

private:
	int					Value;
	static const int	Bits = 8;

public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& original);
	~Fixed();
	Fixed&	operator=(const Fixed& original);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt( void ) const;

};

std::ostream&	operator<<(std::ostream& cout, Fixed& original);
std::ostream&	operator<<(std::ostream& cout, const Fixed& original);
