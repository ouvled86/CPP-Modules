/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:35:59 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/04/27 15:47:45 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float	absVal(float val)
{
	// std::cout << val << '\n';
	if (val < 0)
		return (val * -1);
	return (val);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	triangleArea;
	float	abpArea;
	float	apcArea;
	float	pbcArea;
	float	total;
	
	triangleArea = absVal(a.getXVal() * (b.getYVal() - c.getYVal()) + b.getXVal() * (c.getYVal() - a.getYVal()) + c.getXVal() * (a.getYVal() - b.getYVal())) / 2;
	abpArea = absVal(a.getXVal() * (b.getYVal() - point.getYVal()) + b.getXVal() * (point.getYVal() - a.getYVal()) + point.getXVal() * (a.getYVal() - b.getYVal())) / 2;
	apcArea = absVal(a.getXVal() * (point.getYVal() - c.getYVal()) + point.getXVal() * (c.getYVal() - a.getYVal()) + c.getXVal() * (a.getYVal() - point.getYVal())) / 2;
	pbcArea = absVal(point.getXVal() * (b.getYVal() - c.getYVal()) + b.getXVal() * (c.getYVal() - point.getYVal()) + c.getXVal() * (point.getYVal() - b.getYVal())) / 2;
	total = abpArea + apcArea + pbcArea;
	if (total == triangleArea && abpArea && apcArea && pbcArea)
		return (true);
	return (false);
}