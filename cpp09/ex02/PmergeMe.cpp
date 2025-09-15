/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 16:30:08 by ouvled            #+#    #+#             */
/*   Updated: 2025/09/14 19:04:18 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Default constructor
PmergeMe::PmergeMe(void)
{
	return ;
}

// Full constructor
PmergeMe::PmergeMe(std::string &input)
{
	std::string::iterator	it = input.begin();
	std::string::iterator	it2 = input.begin();

	parseInput(this->_cnt1, it, it2, input.end());

	clock_t	start = clock();
	// this->_cnt2 = this->_cnt1;
	std::copy(this->_cnt1.begin(), this->_cnt1.end(), std::back_inserter(this->_cnt2));
	clock_t	end = clock();
	this->_stopWatchDeque = static_cast<double>(end - start);

	start = clock();
	std::copy(this->_cnt1.begin(), this->_cnt1.end(), std::back_inserter(this->_cnt3));
	end = clock();
	this->_stopWatchList = static_cast<double>(end - start);

	std::cout << "Deque timer: " << this->_stopWatchDeque << " - List timer: " << this->_stopWatchList << std::endl;
	return ;
}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void) other;
	return ;
}

// Destructor
PmergeMe::~PmergeMe(void)
{
	return ;
}

// Assignment operator overload
PmergeMe	&PmergeMe::operator=(const PmergeMe &other)
{
	(void) other;
	return (*this);
}

std::string	mergeInput(char **av, int count)
{
	std::string	ret;

	for (int i = 1; i < count; i++)
	{
		ret += av[i];
		if (i != count - 1)
			ret += " ";
	}
	return (ret);
}

bool	badInput(std::string::iterator it, std::string::iterator it2)
{
	(void)it2;
	while (*it != *it2)
	{
		if (!isdigit(*it) && *it != ' ' && *it != '+' && *it != '-')
			return (true);
		it++;
	}
	return (false);
}

void	parseInput(std::deque<int> &cnt, std::string::iterator it, std::string::iterator it2, std::string::iterator ite)
{
	double	num;

	while (*it2)
	{
		while (*it2 && *it2 != ' ')
			it2++;
		if (badInput(it, it2))
		{
			std::cerr << "Error: bad input." << std::endl;
			exit (200);
		}
		num = atof(std::string(it, it2).c_str());
		if (num < 0 || num > INT_MAX)
		{
			if (num < 0) std::cerr << "Error: input contains a negative number: " << num << std::endl;
			else std::cerr << "Error: input contains a large number: " << num << std::endl;
			exit(201);
		}

		cnt.push_back(num);

		if (it2 != ite)
			it2++;
		it = it2;
	}
}
