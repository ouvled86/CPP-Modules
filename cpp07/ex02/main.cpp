/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:42:47 by ouvled            #+#    #+#             */
/*   Updated: 2025/08/28 17:50:46 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// Do not forget to check memory leaks before evaluation!

int main(void)
{

	Array<int> meow1;
	Array<int> meow2(4);
	Array<char> meow3(12);
	Array<float> meow4(10);

	std::cout << "meow2[0] before initialization: " << meow2[0] << std::endl;
	meow2[0] = 86;
	std::cout << "meow2[0] after initialization: " << meow2[0] << std::endl;
	// meow2[4] = -86;  std::out_of_range is thrown when uncommented
	std::cout << "The size of meow 4 is: " << meow4.size() << std::endl;

	meow3[0] = 'H';
	meow3[1] = 'e';
	meow3[2] = 'l';
	meow3[3] = 'l';
	meow3[4] = 'o';
	meow3[5] = ' ';
	meow3[6] = 'M';
	meow3[7] = 'e';
	meow3[8] = 'o';
	meow3[9] = 'w';
	meow3[10] = '!';
	meow3[11] = '\n';

	for (size_t i = 0; i < meow3.size(); i++)
		std::cout << meow3[i];

}