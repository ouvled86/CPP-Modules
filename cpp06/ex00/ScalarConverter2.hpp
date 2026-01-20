/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:10:55 by ouvled            #+#    #+#             */
/*   Updated: 2025/08/21 22:07:31 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>

class ScalarConverter
{
private:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();
public:
	static void	convert(const char *input);
};

char	findType(const char *input);
bool	isChar(const char *input);
bool	isInt(const char *input);
bool	isDouble(const char *input);
bool	isFloat(const char *input);

#endif
