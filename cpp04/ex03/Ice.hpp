/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:11:55 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/05/23 14:11:56 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice(void);
	Ice(const Ice& other);
	Ice		&operator=(const Ice &other);
	~Ice();
	Ice*	clone() const;
	void	use(ICharacter& target);
};

#endif

