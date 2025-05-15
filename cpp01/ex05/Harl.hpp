/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:59:47 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/05/12 09:10:54 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	Harl {
private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
	
public:
	void	complain( std::string level );
};
