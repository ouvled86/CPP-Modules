/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 16:30:08 by ouvled            #+#    #+#             */
/*   Updated: 2025/09/18 01:07:34 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Default constructor
PmergeMe::PmergeMe(void)
{
	return ;
}

PmergeMe::PmergeMe(std::deque<int> cnt) : _cnt1(cnt)
{
	return ;
}

std::deque<std::pair<int, int> >	breakSortDeque(std::deque<int> cnt1, size_t size)
{
	std::deque<std::pair<int, int> >	pairs;

	for (size_t i = 0; i < size - 1; i += 2)
		pairs.push_back(std::make_pair(cnt1[i], cnt1[i + 1]));
	
	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		if ((*it).first > (*it).second)
			std::swap((*it).first, (*it).second);
	}

	return (pairs);
}

std::deque<int>	extractLarger(std::deque<std::pair<int, int> > pairs)
{
	std::deque<int>	ret;

	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
		ret.push_back((*it).second);
	return (ret);
}

std::deque<int>	genJacobsthal(size_t size)
{
	std::deque<int>	ret;

	ret.push_back(1);
	ret.push_back(3);
	
	while (static_cast<int>(size) > ret.back())
	{
		ret.push_back(ret[ret.size() - 1] + 2 * ret[ret.size() - 2]);
	}
	return (ret);
}

void	insertInMc(std::deque<int> &mainChain, int element)
{
	size_t	min = 0;
	size_t	max = mainChain.size();

	while (min < max)
	{
		size_t	mid = min + (max - min) / 2;
		if (mainChain[mid] < element)
			min = mid + 1;
		else
			max = mid;
	}
	mainChain.insert(mainChain.begin() + min, element);
}

void	binaryInsert(std::deque<int> &mainChain, std::deque<std::pair<int, int> > pairs)
{
	size_t			pairsSize = pairs.size();
	std::deque<int>	jacobsthalSequence = genJacobsthal(pairsSize);
	
	size_t			i = 0;
	if (pairs.size())
		insertInMc(mainChain, pairs[0].first);
		
	while (i < jacobsthalSequence.size())
	{
		size_t	min;
		if (i != 0)
			min = jacobsthalSequence[i - 1] + 1;
		else
			min = 1;
		size_t max = jacobsthalSequence[i];
		for (size_t k = max; k >= min; k--)
		{
			if (k < pairsSize)
				insertInMc(mainChain, pairs[k].first);
		}
		i++;
	}
}

// This function sorts an std::deque<int>, size n
// It uses Ford-Johnson algorithm
// First off, we break the initial sequence into pairs, size of n/2
// Then we sort them using n/2 comprasions
// After that we create a list of the larger elements and sort them recursively
void	sortDeque(std::deque<int> &container)
{
	if (container.size() <= 1) return ;

	std::deque<std::pair<int, int> >	pairs = breakSortDeque(container, container.size());
	std::deque<int>						largerElements = extractLarger(pairs);

	if (container.size() % 2 != 0)
		largerElements.push_back(container[container.size() - 1]);
	sortDeque(largerElements);
	std::deque<int>						mainChain = largerElements;
	std::cout << "Main chain is: ";
	for (size_t i = 0; i < mainChain.size(); i++)
		std::cout << mainChain[i] << " ";
	std::cout << std::endl;
	binaryInsert(mainChain, pairs);
	container.clear();
	container = mainChain;

}

// void	sortList(std::list<int> container)
// {
	
// }

// Full constructor
PmergeMe::PmergeMe(std::string &input)
{
	std::string::iterator	it = input.begin();
	std::string::iterator	it2 = input.begin();

	parseInput(this->_cnt1, it, it2, input.end());

	clock_t	start = clock();
	std::copy(this->_cnt1.begin(), this->_cnt1.end(), std::back_inserter(this->_cnt2));
	sortDeque(this->_cnt2);
	std::cout << "-> largerElements size: " << _cnt2.size() << std::endl;
	for (size_t i = 0; i < _cnt2.size(); i++)
		std::cout << "Position at: " << i << " is: " << _cnt2[i] << std::endl;
	clock_t	end = clock();
	this->_stopWatchDeque = static_cast<double>(end - start);

	std::cout << "Time taken to sort std::deque<int> in microseconds is: " << this->_stopWatchDeque << std::endl;

	// start = clock();
	// std::copy(this->_cnt1.begin(), this->_cnt1.end(), std::back_inserter(this->_cnt3));
	// sortList(this->_cnt3);
	// end = clock();
	// this->_stopWatchList = static_cast<double>(end - start);

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
