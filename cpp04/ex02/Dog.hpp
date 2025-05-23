/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:44:58 by ouvled            #+#    #+#             */
/*   Updated: 2025/05/21 12:57:08 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain	*brain;

public:
	Dog(void);
	Dog(const Dog& other);
	Dog		&operator=(const Dog &other);
	~Dog();
	void	makeSound();
};

#endif

