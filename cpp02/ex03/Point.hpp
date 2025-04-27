/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:06:10 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/04/27 14:47:57 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>
#include "Fixed.hpp"

class	Point
{
	
	Fixed const	x;
	Fixed const	y;

public:
	Point(void);
	Point(const float X, const float Y);
	Point(const Point& original);
	Point&	operator=(const Point& original);
	~Point(void);
	int	getXVal(void) const;
	int	getYVal(void) const;


};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
