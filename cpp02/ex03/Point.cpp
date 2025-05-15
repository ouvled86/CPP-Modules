/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:06:06 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/05/15 12:57:26 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(Fixed()), y(Fixed())
{
	return ;
}

Point::Point(const float X, const float Y) : x(Fixed(X)), y(Fixed(Y))
{
	return ;
}

Point::Point(const Point& original) : x(original.x), y(original.y)
{
	return ;
}

Point&	Point::operator=(const Point& original)
{
	(void)original;
	std::cout << "Assignment operator is a no-op because class attributes are constant" << '\n';
	return (*this);
}

Point::~Point(void)
{
	return ;
}

float	Point::getXVal(void) const
{
	return(this->x.toFloat());
}

float	Point::getYVal(void) const
{
	return(this->y.toFloat());
}
