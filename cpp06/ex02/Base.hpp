/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:03:34 by ouvled            #+#    #+#             */
/*   Updated: 2025/08/24 19:57:16 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <ctime>
# include <cstdlib>
# include <iostream>

class Base
{
public:
	virtual ~Base();
};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif