/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:44:47 by ouvled            #+#    #+#             */
/*   Updated: 2025/05/21 12:11:32 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include <string>

class Animal
{
protected:
	std::string		type;

public:
	Animal(void);
	Animal(const Animal& other);
	Animal			&operator=(const Animal &other);
	virtual ~Animal();
	virtual void	makeSound();
};

#endif

