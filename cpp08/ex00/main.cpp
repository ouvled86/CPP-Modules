/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:38:13 by ouvled            #+#    #+#             */
/*   Updated: 2025/08/31 17:57:36 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "easyfind.hpp"

int main(void)
{
	std::vector<int> v1;
	std::list<int> l1;
	std::string s = "meow";

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	l1.push_back(6);
	l1.push_back(7);
	l1.push_back(8);
	l1.push_back(9);
	l1.push_back(0);
	
	// test cases where easyfind fails and returns 1
	std::cout << "easyfind(l1, 1): " << easyfind(l1, 1) << std::endl;
	std::cout << "easyfind(v1, 6): " << easyfind(v1, 6) << std::endl;
	
	// test cases where easyfind successes and returns 0
	std::cout << "easyfind(l1, 0): " << easyfind(l1, 0) << std::endl;
	std::cout << "easyfind(v1, 2): " << easyfind(v1, 2) << std::endl;

	// non-integer container
	std::cout << "easyfind(s, 10): " << easyfind(s, 10) << std::endl;
}