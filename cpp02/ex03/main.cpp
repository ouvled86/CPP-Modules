/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:06:17 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/04/27 15:51:06 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
	// Triangle
	Point a(0, 0);
	Point b(5, 0);
	Point c(2, 4);

	// Points inside of the triangle
	Point p1(2, 1);
	Point p2(3, 2);
	Point p3(1, 1);
	
	// Points on the edge of the triangle
	Point p12(1, 2);
	Point p22(0, 0);
	Point p32(3.5, 0);
	
	// Points outside of the triangle
	Point p13(5, 5);
	Point p23(-1, 0);
	Point p33(2, 5);
	
	// Tests
	std::cout << bsp(a, b, c, p1) << '-' << bsp(a, b, c, p2) << '-' << bsp(a, b, c, p3) << '\n';
	std::cout << bsp(a, b, c, p12) << '-' << bsp(a, b, c, p22) << '-' << bsp(a, b, c, p32) << '\n';
	std::cout << bsp(a, b, c, p13) << '-' << bsp(a, b, c, p23) << '-' << bsp(a, b, c, p33) << '\n';
	
}