/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:10:48 by ouvled            #+#    #+#             */
/*   Updated: 2025/08/22 17:41:44 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <limits>
#include <cstdlib>
#include <cstring>
#include <cmath>

// Default constructor
ScalarConverter::ScalarConverter(void)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << "Copy constructor called" << std::endl;
	(void) other;
	return ;
}

// Assignment operator overload
ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &other)
{
	std::cout << "Assignment operator called" << std::endl;
	(void) other;
	return (*this);
}

// Destructor
ScalarConverter::~ScalarConverter(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

void	assignToHolders(const char *input, char type, char **cholder, int **iholder, float **fholder, double **dholder)
{
	switch (type) {
		case 'c': {
			**cholder = input[0];
			**iholder = static_cast<int>(**cholder);
			**fholder = static_cast<float>(**cholder);
			**dholder = static_cast<double>(**cholder);
			break ;
		}
		case 'i': {
			**iholder = atoi(input);
			if (**iholder >= 0 && **iholder <= 255)
				**cholder = static_cast<char>(**iholder);
			**fholder = static_cast<float>(**iholder);
			**dholder = static_cast<double>(**iholder);
			break ;
		}
		case 'f': {
			**fholder = static_cast<float>(std::atof(input));
			if (**fholder >= std::numeric_limits<int>::min() && **fholder <= std::numeric_limits<int>::max())
				**iholder = static_cast<int>(**fholder);
			else
				*iholder = NULL;
			if (*iholder && (**iholder >= 0 && **iholder <= 255))
				**cholder = static_cast<char>(**fholder);
				else
				*cholder = NULL;
			**dholder = static_cast<double>(**fholder);
			break ;
		}
		case 'd': {
			**dholder = static_cast<double>(std::atof(input));
			if (**dholder >= std::numeric_limits<float>::min() && **dholder <= std::numeric_limits<float>::max())
				**fholder = static_cast<float>(**dholder);
			else
				*fholder = NULL;
			if (**dholder >= std::numeric_limits<int>::min() && **dholder <= std::numeric_limits<int>::max())
				**iholder = static_cast<int>(**dholder);
			else
				*iholder = NULL;
			if (*iholder && (**iholder >= 0 && **iholder <= 255))
				**cholder = static_cast<char>(**dholder);
			else
				*cholder = NULL;
			break ;
		}
	}
}

bool	fractionalPart(const char *input)
{
	bool	ret = false;
	int		counter = 0;

	if (strlen(input) > 1 && !(input[1] >= '0' && input[1] <= '9'))
		return true;
	for (int i = 0; input[i]; i++)
	{
		if (input[i] == '.')
		{
			while (input[i])
			{
				i++;
				counter++;
				if (counter >= 5 && input[i] >= '1' && input[i] <= '5')
				{
					if (input[i + 1])
						return true;
					return false;
				}
				if (input[i] >= '1' && input[i] <= '9')
				{
					ret = true;
					std::cout << "true" << std::endl;
					break ;
				}
			}
		}
	}
	return (ret);
}

bool hasFractionalPart(const char *str) {
	if (strlen(str) > 1 && !(str[1] >= '0' && str[1] <= '9'))
		return true;
    double value = std::atof(str);
    const double epsilon = 1e-6;
    return std::fabs(value - std::floor(value)) > epsilon;
}

void	printValues(char *cholder, int *iholder, float *fholder, double *dholder, bool flag)
{
	std::cout << "char: ";
	if (cholder && (*cholder >= 32 && *cholder <= 126))
		std::cout << '\'' << *cholder << '\'' << std::endl;
	else if (cholder && !(*cholder >= 32 && *cholder <= 126))
		std::cout << "Not Displayable" << std::endl;
	else
		std::cout << "Impossible" << std::endl;
	std::cout << "int: ";
	if (iholder)
		std::cout << *iholder << std::endl;
	else
		std::cout << "Impossible" << std::endl;
	std::cout << "float: ";
	if (*dholder != *dholder)
		std::cout << "nanf" << std::endl;
	else if (*dholder == INFINITY)
		std::cout << "inff" << std::endl;
	else if (*dholder == -INFINITY)
		std::cout << "-inff" << std::endl;
	else if (fholder && !flag)
		std::cout << *fholder << ".0f" << std::endl;
	else if (fholder && flag)
		std::cout << *fholder << "f" << std::endl;
	else
		std::cout << "Impossible" << std::endl;
	std::cout << "double: ";
	if (dholder && !flag)
		std::cout << *dholder << ".0" << std::endl;
	else if (dholder && flag)
		std::cout << *dholder << std::endl;
	else
		std::cout << "Impossible" << std::endl;
}

void	ScalarConverter::convert(const char *input)
{
	char	*cholder = new char;
	int		*iholder = new int;
	float	*fholder = new float;
	double	*dholder = new double;
	char	type = 0;
	
	type = findType(input);
	assignToHolders(input, type, &cholder, &iholder, &fholder, &dholder);
	printValues (cholder, iholder, fholder, dholder, hasFractionalPart(input));
	delete cholder;
	delete iholder;
	delete fholder;
	delete dholder;
}

char	findType(const char *input)
{
	double holder = atof(input);
	if (!input)
		return ('n');
	if (isChar(input))
		return ('c');
	if (isInt(input) && holder >= std::numeric_limits<int>::min() && holder <= std::numeric_limits<int>::max())
		return ('i');
	if (isFloat(input))
		return ('f');
	if (isDouble(input))
		return ('d');
	return ('n');
}

bool	isChar(const char *input)
{
	unsigned char	c = static_cast<unsigned char>(*input);
	if (strlen(input) == 1 && ((c > 0 && c <= 47) || (c >= 58 && c < 255)))
		return (true);
	return (false);
}

bool	isInt(const char *input)
{
	bool	ret = true;

	if ((input[0] < '0' && input[0] > '9') && input[0] != '-' && input[0] != '+')
		ret = false;
	for (int i = 1; input[i]; i++)
	{
		if (input[i] < '0' || input[i] > '9')
			ret = false;
	}
	return (ret);
}

bool	isDouble(const char *input)
{
	bool	ret = true;

	if (input[0] == 'n' && input[1] == 'a' && input[2] == 'n' && input[3] == '\0')
		return (true);
	// if (!(input[0] >= '0' && input[0] <= '9') && input[0] != '-' && input[0] != '+')
	if ((input[0] < '0' && input[0] > '9') && input[0] != '-' && input[0] != '+')
		ret = false;
	if (input[1] == 'i' && input[2] == 'n' && input[3] == 'f' && input[4] == '\0')
		return (true);
	for (int i = 1; input[i]; i++)
	{
		if ((input[i] < '0' || input[i] > '9') && input[i] != '.')
			ret = false;
	}
	return (ret);
}

bool	isFloat(const char *input)
{
	bool	ret = true;
	size_t	i = 1;

	if (input[0] == 'n' && input[1] == 'a' && input[2] == 'n' && input[3] == 'f' && input[4] == '\0')
		return (true);
	if ((input[0] < '0' && input[0] > '9') && input[0] != '-' && input[0] != '+')
		ret = false;
	if (input[1] == 'i' && input[2] == 'n' && input[3] == 'f' && input[4] == 'f' && input[5] == '\0')
		return (true);
	while (i < strlen(input) - 1)
	{
		if ((input[i] < '0' || input[i] > '9') && input[i] != '.')
			ret = false;
		i++;
	}
	if (input[i] != 'f')
		ret = false;
	return (ret);
}
