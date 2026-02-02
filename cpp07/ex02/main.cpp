/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:42:47 by ouvled            #+#    #+#             */
/*   Updated: 2026/02/02 04:29:43 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// Do not forget to check memory leaks before evaluation!

// int main(void)
// {

// 	Array<int> meow1;
// 	Array<int> meow2(4);
// 	Array<char> meow3(12);
// 	Array<float> meow4(10);

// 	std::cout << "meow2[0] before initialization: " << meow2[0] << std::endl;
// 	meow2[0] = 86;
// 	std::cout << "meow2[0] after initialization: " << meow2[0] << std::endl;
// 	// meow2[4] = -86;  std::out_of_range is thrown when uncommented
// 	std::cout << "The size of meow 4 is: " << meow4.size() << std::endl;

// 	meow3[0] = 'H';
// 	meow3[1] = 'e';
// 	meow3[2] = 'l';
// 	meow3[3] = 'l';
// 	meow3[4] = 'o';
// 	meow3[5] = ' ';
// 	meow3[6] = 'M';
// 	meow3[7] = 'e';
// 	meow3[8] = 'o';
// 	meow3[9] = 'w';
// 	meow3[10] = '!';
// 	meow3[11] = '\n';

// 	for (size_t i = 0; i < meow3.size(); i++)
// 		std::cout << meow3[i];

// }

#include <iostream>
#include <cstdlib>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
		const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
	std::cout << numbers.size() <<"\n";
    {
		Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
		std::cout << numbers[i] << std::endl;
    }
    delete [] mirror;//
    return 0;
}