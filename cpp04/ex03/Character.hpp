/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:11:44 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/05/23 17:13:18 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

typedef struct	Node
{
	AMateria	*m;
	Node		*next;
}				Node;

class Character : public ICharacter
{
private:
	std::string			Name;
	AMateria			*Slots[4];
	Node				*col;

public:
	Character(void);
	Character(std::string const& name);
	Character(const Character& other);
	Character&			operator=(const Character &other);
	~Character();

	std::string const&	getName() const;
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);
	Node*				insertNode(AMateria *m);
	void				freeMemory(void);
};

#endif

