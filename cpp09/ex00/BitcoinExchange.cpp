/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:55:36 by ouvled            #+#    #+#             */
/*   Updated: 2025/09/09 20:11:52 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <string>
#include <cstdlib>
#include <iomanip>

// Default constructor
BitcoinExchange::BitcoinExchange(void)
{
	return ;
}

// Full constructor
BitcoinExchange::BitcoinExchange(std::ifstream &data, std::ifstream &input)
{
	this->_data = parseData(data);
	this->_input = parseInput(input);
	return ;
}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	(void) other;
	return ;
}

// Destructor
BitcoinExchange::~BitcoinExchange(void)
{
	return ;
}

// Assignment operator overload
BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other)
{
	(void) other;
	return (*this);
}

void	BitcoinExchange::printData(void) const
{
	// Loop over _input, check for errors. If no errors, find corresponding element 
	// in _data and calculate rate * value then print it
	// algo: lower_bound()
	std::vector<std::pair<std::string, float> >::const_iterator	it = this->_input.begin();
	std::map<std::string, float>::const_iterator				it2;
	
	while (it != this->_input.end())
	{
		if ((*it).first == "BIG_VALUE")
			std::cerr << "Error: value is too large." << std::endl;
		else if ((*it).first == "NEG_VALUE")
			std::cerr << "Error: value is negative." << std::endl;
		else if ((*it).first == "BAD_FORMAT")
			std::cerr << "Error: bad input." << std::endl;
		else
		{
			it2 = this->_data.lower_bound((*it).first);
			if (it2 != this->_data.begin())
			{
				it2--;
				std::cout << (*it).first << " => " << (*it).second << " = " << (*it).second * (*it2).second << std::endl;
			}
			else
				std::cerr << "Error: could not find entered date in database." << std::endl;
		}
		it++;
	}
}

std::map<std::string, float>	parseData(std::ifstream &data)
{
	std::map<std::string, float>	ret;
	std::pair<std::string, float>	p;
	std::string						buff;
	std::string::iterator			it;

	std::getline(data, buff);
	while (std::getline(data, buff))
	{
		it = buff.begin();
		while (*it != ',')
			it++;
		p.first = std::string(buff.begin(), it);
		p.second = atof(std::string(it + 1, buff.end()).c_str());
		ret.insert(p);
	}
	return (ret);
}

std::vector<std::pair<std::string, float> >	parseInput(std::ifstream &input)
{
	std::vector<std::pair<std::string, float> >	ret;
	std::pair<std::string, float>				p;
	std::string									buff;
	std::string::iterator						it;

	std::getline(input, buff);
	while (std::getline(input, buff))
	{
		it = buff.begin();
		while (*it && ((*it >= '0' && *it <= '9') || *it == '-') && *it != '|')
			it++;
		p.first = std::string(buff.begin(), it);
		if (*it)
			p.second = atof(std::string(it + 2, buff.end()).c_str());
		if (p.second > 1000)
			p.first = "BIG_VALUE";
		else if (p.second < 0)
			p.first = "NEG_VALUE";
		if (badFormat(buff.begin()))
			p.first = "BAD_FORMAT";
		if (!buff.empty())
			ret.push_back(p);
		// std::cout << "Pair's data: " << buff << " - pair's amount: " << p.second << std::endl;
	}
	return (ret);
}

bool	badFormat(std::string::iterator s)
{
	double	year = 0;
	double	month = 0;
	double	day = 0;
	int		i = 4;

	while (*s && (*s >= '0' && *s <= '9') && i)
	{
		year = (year * 10) + (*s - '0');
		s++;
		i--;
	}
	if (*s != '-' || i != 0)
		return (true);

	s++;
	i = 2;
	while (*s && (*s >= '0' && *s <= '9') && i)
	{
		month = (month * 10) + (*s - '0');
		s++;
		i--;
	}
	if (*s != '-' || i != 0)
		return (true);

	s++;
	i = 2;
	while (*s && (*s >= '0' && *s <= '9') && i)
	{
		day = (day * 10) + (*s - '0');
		s++;
		i--;
	}
	if (*s != ' ' || *(s + 1) != '|' || *(s + 2) != ' ' || i != 0)
		return (true);

	s += 3;
	while (*s)
	{
		if (!(*s >= '0' && *s <= '9') && *s != '.' && *s != '-')
			return (true);
		s++;
	}
	if ((year < 1970 || year > 2022) || (month < 1 || month > 12) || (day < 1 || day > 31))
		return (true);
	if ((year == 2022 && month > 3) || (year == 2022 && month == 3 && day > 29))
		return (true);

	return (false);
}

