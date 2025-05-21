/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:45:10 by ouvled            #+#    #+#             */
/*   Updated: 2025/05/21 11:45:11 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>
# include <string>

class WrongAnimal
{
protected:
	std::string	type;

public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal	&operator=(const WrongAnimal &other);
	~WrongAnimal();
	void		makeSound();

};

#endif

