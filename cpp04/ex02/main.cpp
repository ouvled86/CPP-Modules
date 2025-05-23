/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:45:01 by ouvled            #+#    #+#             */
/*   Updated: 2025/05/21 13:36:12 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal	*animals[20];
	
  for (int i = 0; i < 10; i++)
    animals[i] = new Dog();
  for (int i = 10; i < 20; i++)
    animals[i] = new Cat();
  for (int i = 0; i < 20; i++)
    delete animals[i];
}

