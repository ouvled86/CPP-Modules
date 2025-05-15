/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:34:13 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/05/10 13:43:13 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class	Weapon {
private:
	std::string			type;

public:
	Weapon( void );
	Weapon( const std::string& wName );
	~Weapon ( void );
	const std::string&	getType( void ) const;
	void				setType( const std::string &newType );
};

