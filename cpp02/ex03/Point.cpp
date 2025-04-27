/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:06:06 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/04/27 15:09:05 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(Fixed()), y(Fixed())
{
	
}

Point::Point(const float X, const float Y) : x(Fixed(X)), y(Fixed(Y))
{

}

Point::Point(const Point& original) : x(original.x), y(original.y)
{
	
}

Point&	Point::operator=(const Point& original)
{
	if (this != &original)
	{
		*this = original;
	}
	return (*this);
}

Point::~Point(void)
{
	
}

int	Point::getXVal(void) const
{
	// std::cout << "x is: " << this->x.toFloat() << '\n';
	return(this->x.toFloat());
}

int	Point::getYVal(void) const
{
	// std::cout << "y is: " << this->y.toFloat() << '\n';
	return(this->y.toFloat());
	
}