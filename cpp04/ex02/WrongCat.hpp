/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:45:18 by ouvled            #+#    #+#             */
/*   Updated: 2025/05/21 12:12:53 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat(void);
	WrongCat(const WrongCat& other);
	WrongCat	&operator=(const WrongCat &other);
	~WrongCat();
	void		makeSound();

};

#endif

