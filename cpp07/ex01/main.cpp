/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:12:08 by ouvled            #+#    #+#             */
/*   Updated: 2025/08/27 19:36:25 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template < typename T >
void	print_element(const T &e) { std::cout << e << std::endl; }

void	increment_element(int &e) { e++; }

void	decrement_element(int &e) { e--; }

void	toupper(char &e) { e -= 32; }

int main(void)
{
	int	arr[5] = {86, 86, 86, 86, 86};
	char	meow[] = "meow meow nigga";
	
	iter(arr, 5, print_element);
	std::cout << std::endl;
	iter(arr, 5, increment_element);
	iter(arr, 5, print_element);
	std::cout << std::endl;
	iter(arr, 1, decrement_element);
	iter(arr + 2, 3, increment_element);
	iter(arr + 3, 2, increment_element);
	iter(arr + 4, 1, increment_element);
	iter(arr, 5, print_element);
	std::cout << std::endl;
	iter(meow, 15, toupper);
	iter(meow, 15, print_element);
}
