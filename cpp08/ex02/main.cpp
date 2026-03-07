/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:28:38 by ouvled            #+#    #+#             */
/*   Updated: 2025/09/02 19:27:28 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	MutantStack<int>			myStack;
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
		myStack.push(rand() % 100);
	const MutantStack<int>		myStack2 = myStack;
	std::cout << "Size: " << myStack.size() << std::endl;
	myStack.push(17);
	std::cout << "Top: " << myStack.top() << std::endl;
	myStack.pop();
	std::cout << "Size of myStack: " << myStack.size() << std::endl;
	std::cout << "Size of myStack2: " << myStack2.size() << std::endl;
	myStack.push(3);
	myStack.push(5);
	myStack.push(737);
	std::cout << "Size of myStack: " << myStack.size() << std::endl;
	std::cout << "Size of myStack2: " << myStack2.size() << std::endl;

	myStack.push(0);
	MutantStack<int>::iterator it = myStack.begin();
	MutantStack<int>::iterator ite = myStack.end();
	++it;
	--it;
	std::cout << "Iterating through myStack:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	std::cout << "Iterating through myStack2 in reverse:" << std::endl;
	MutantStack<int>::const_reverse_iterator it2 = myStack2.rbegin();
	MutantStack<int>::const_reverse_iterator ite2 = myStack2.rend();
	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << " ";
		++it2;
	}
	std::cout << std::endl;
	return 0;
}
