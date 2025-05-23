/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:44:52 by ouvled            #+#    #+#             */
/*   Updated: 2025/05/21 12:56:25 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain	*brain;

public:
	Cat(void);
	Cat(const Cat& other);
	Cat		&operator=(const Cat &other);
	~Cat();
	void	makeSound();
};

#endif

