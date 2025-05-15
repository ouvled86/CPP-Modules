/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:30:29 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/05/13 11:06:49 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed {
private:
	int					Value;
	static const int	Bits;
public:
	Fixed();
	Fixed(const Fixed& original);
	Fixed& operator=(const Fixed& original);
	~Fixed();
	int					getRawBits(void) const;
	void				setRawBits(int const raw);
};
