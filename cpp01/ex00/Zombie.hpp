/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:24:42 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/05/10 11:40:24 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Zombie {
private:
	std::string name;

public:
	Zombie( void );
	Zombie( std::string zName );
	~Zombie( void );
	void announce( void );
};

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );
