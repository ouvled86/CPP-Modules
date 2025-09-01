/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:02:46 by ouvled            #+#    #+#             */
/*   Updated: 2025/09/01 20:41:16 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	std::vector<int>	vec1;
	vec1.push_back(9999999);
	vec1.push_back(1000);
	vec1.push_back(1002);
	vec1.push_back(999999);
	// vec1.push_back(1); // Uncomment to test exception throwing
	Span span1(7);
	// span1.shortestSpan(); // Uncomment to test exception throwing
	span1.addNumber(2);
	span1.addNumber(100);
	span1.addNumber(5);
	// span1.addNumber(10000); // Uncomment to test exception throwing
	Span span2(span1);
	Span span3;
	span3 = span2;
	span3.addRange(vec1.begin(), vec1.end());
	std::cout << "Shortest Span is: " << span3.shortestSpan() << std::endl;
	std::cout << "Longest Span is: " << span3.longestSpan() << std::endl;
}
