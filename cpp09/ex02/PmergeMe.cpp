/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 16:30:08 by ouvled            #+#    #+#             */
/*   Updated: 2025/09/16 17:07:09 by ouel-bou         ###   ########.fr       */
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

std::deque<int>	halfAndSort(std::deque<int> cnt1, std::deque<std::pair<int, int> > pairs, size_t size)
{
	for (size_t i = 0; i < size - 1; i += 2)
		pairs.push_back(std::make_pair(cnt1[i], cnt1[i + 1]));
	
	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		if ((*it).first > (*it).second)
			std::swap((*it).first, (*it).second);
	}

	std::deque<int>	ret;
	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		ret.push_back((*it).second);
	}
	if (size % 2)
		ret.push_back(cnt1[size - 1]);

	return (ret);
}

void	PmergeMe::sortDeque(void)
{
	std::deque<std::pair<int, int> >	pairs;
	std::deque<int>						mainChain;
	std::deque<int>						largeElements;
	size_t								size = this->_cnt1.size();
	// int									extra = -1;

	if (largeElements.size() <= 1) return ;
	if (largeElements.size() == 2)
	{
		
	}
	largeElements = halfAndSort(this->_cnt1, pairs, size);
	int j = 1;
	std::cout << "Size is: " << largeElements.size() << std::endl;
	for (std::deque<int>::iterator it = largeElements.begin(); it != largeElements.end(); it++)
	{
		std::cout << "Large element at pos " << j << ": " << *it << std::endl;
		j++;
	}
	// for (size_t i = 0; i < size - 1; i += 2)
	// 	pairs.push_back(std::make_pair(this->_cnt1[i], this->_cnt1[i + 1]));
	// if (size % 2)
	// 	extra = this->_cnt1[size - 1];
	// if (extra != -1)
	// 	std::cout << "B extra: " << extra << std::endl;
}

void	PmergeMe::sortList(void)
{
	
}

void	PmergeMe::printInfo(void)
{
	std::deque<int>::iterator it = this->_cnt1.begin();
	std::deque<int>::iterator ite = this->_cnt1.end();
	std::cout << "Sequence before sorting: ";
	while (it != ite - 1)
		std::cout << *it << " ";
	std::cout << *it << std::endl;
	std::cout << "Sequence after sorting: ";
	it = this->_cnt2.begin();
	ite = this->_cnt2.end();
	while (it != ite - 1)
		std::cout << *it << " ";
	std::cout << *it << std::endl;
	std::cout << "Time to process a range of " << this->_cnt1.size() << " elements with std::deque : " << this->_stopWatchDeque << " us" << std::endl;
	std::cout << "Time to process a range of " << this->_cnt1.size() << " elements with std::list : " << this->_stopWatchList << " us" << std::endl;
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
