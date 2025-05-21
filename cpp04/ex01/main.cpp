/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:45:01 by ouvled            #+#    #+#             */
/*   Updated: 2025/05/21 12:16:40 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		Animal	*ins1 = new Animal();
		Animal	*ins2 = new Cat();
		Animal	*ins3 = new Dog();
		Animal	ins4;

		ins4 = *ins2;
		ins1->makeSound();
		ins2->makeSound();
		ins3->makeSound();
		ins4.makeSound();

		delete(ins1);
		delete(ins2);
		delete(ins3);
	}
	{
		WrongAnimal	*ins1 = new WrongAnimal();
		WrongAnimal	*ins2 = new WrongCat();

		ins1->makeSound();
		ins2->makeSound();

		delete(ins1);
		delete(ins2);
	}
}

