/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:16:21 by ouvled            #+#    #+#             */
/*   Updated: 2025/08/24 18:41:47 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <iostream>
# include <stdint.h>
# include "Data.hpp"

class Serializer
{
private:
	Serializer(void);
	Serializer(const Serializer& other);
	Serializer &operator=(const Serializer &other);
	~Serializer();
public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};

#endif

