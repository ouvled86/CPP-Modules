/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:11:50 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/05/23 14:11:51 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure(void);
	Cure(const Cure& other);
	Cure	&operator=(const Cure &other);
	~Cure();
	Cure*	clone() const;
	void	use(ICharacter& target);
};

#endif

