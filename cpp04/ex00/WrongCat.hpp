/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:45:18 by ouvled            #+#    #+#             */
/*   Updated: 2025/05/21 11:45:19 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include <iostream>
# include "Animal.hpp"

class WrongCat : public Animal
{
public:
	WrongCat(void);
	WrongCat(const WrongCat& other);
	WrongCat	&operator=(const WrongCat &other);
	~WrongCat();
	void		makeSound();

};

#endif

