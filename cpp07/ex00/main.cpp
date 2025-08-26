/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 19:02:58 by ouvled            #+#    #+#             */
/*   Updated: 2025/08/26 21:17:15 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main(void)
{
	int	a = 1;
	int b = 10;
	float c = 2;
	float d = 2;

	swap(a, b);
	std::cout << "a is: " << a << ", b is: " << b << std::endl;

	std::cout << "a: " << a << ", b: " << b << ". Min(a, b): " << min(a, b) << std::endl;
	std::cout << "a: " << a << ", b: " << b << ". Max(a, b): " << max(a, b) << std::endl;
	std::cout << "&c: " << &c << ", &d: " << &d << ". &Min(c, d): " << &min(c, d) << std::endl;
	std::cout << "&c: " << &c << ", &d: " << &d << ". &Max(c, d): " << &max(c, d) << std::endl;
}