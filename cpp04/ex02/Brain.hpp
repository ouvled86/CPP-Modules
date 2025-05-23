/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:32:07 by ouvled            #+#    #+#             */
/*   Updated: 2025/05/21 13:37:17 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
private:
	std::string			ideas[100];
	int					size;

public:
	Brain(void);
	Brain(const Brain& other);
	Brain				&operator=(const Brain &other);
	~Brain();
	void				addIdea(const std::string& idea);
	std::string			getIdea(int index) const;
	const int&			getSize() const;
};

#endif
