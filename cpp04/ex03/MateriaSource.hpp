/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:12:08 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/05/23 14:12:09 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria*		Srcs[4];

public:
	MateriaSource(void);
	MateriaSource(const MateriaSource& other);
	MateriaSource	&operator=(const MateriaSource &other);
	~MateriaSource();
	void			learnMateria(AMateria* m);
	AMateria*		createMateria(std::string const & type);
};

#endif
