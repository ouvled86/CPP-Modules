#include "PmergeMe.hpp"
#include <algorithm>
#include <climits>
#include <iostream>

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

void	binaryInsertDeque(std::deque<int> &mainChain, std::deque<std::pair<int, int> > pairs)
{
	size_t			pairsSize = pairs.size();
	std::deque<int>	jacobsthalSequence = genJacobsthal(pairsSize);
	
	size_t			i = 0;
	if (pairsSize > 0)
		mainChain.insert(mainChain.begin(), pairs[0].first);
		
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
			if (k < pairsSize) {
				std::deque<int>::iterator bound = std::find(mainChain.begin(), mainChain.end(), pairs[k].second);
				std::deque<int>::iterator insert_pos = std::lower_bound(mainChain.begin(), bound, pairs[k].first);
				mainChain.insert(insert_pos, pairs[k].first);
			}
		}
		i++;
	}
}

void	sortDeque(std::deque<int> &container)
{
	if (container.size() <= 1) 
		return ;

	std::deque<std::pair<int, int> >	pairs = breakSortDeque(container, container.size());
	std::deque<int>						largerElements;
	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
		largerElements.push_back((*it).second);

	sortDeque(largerElements);

	std::deque<std::pair<int, int> > sortedPairs;
	for (size_t i = 0; i < largerElements.size(); ++i)
	{
		for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
		{
			if (it->second == largerElements[i])
			{
				sortedPairs.push_back(*it);
				pairs.erase(it);
				break;
			}
		}
	}
	pairs = sortedPairs;

	std::deque<int>						mainChain = largerElements;
	binaryInsertDeque(mainChain, pairs);

	if (container.size() % 2 != 0) {
		std::deque<int>::iterator insert_pos = std::lower_bound(mainChain.begin(), mainChain.end(), container.back());
		mainChain.insert(insert_pos, container.back());
	}

	container.clear();
	container = mainChain;
}

std::list<std::pair<int, int> >	breakSortList(const std::list<int>& cnt1, size_t size)
{
	std::list<std::pair<int, int> >	pairs;
	std::list<int>::const_iterator it = cnt1.begin();

	for (size_t i = 0; i < size - 1; i += 2) {
		int first = *it;
		it++;
		int second = *it;
		it++;
		if (first > second)
			std::swap(first, second);
		pairs.push_back(std::make_pair(first, second));
	}
	return (pairs);
}



void	binaryInsertList(std::list<int> &mainChain, std::list<std::pair<int, int> >& pairs)
{
	size_t			pairsSize = pairs.size();
	std::deque<int>	jacobsthalSequence = genJacobsthal(pairsSize);
	
	size_t			i = 0;
	if (pairsSize > 0)
		mainChain.insert(mainChain.begin(), pairs.front().first);
		
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
			if (k < pairsSize) {
				std::list<std::pair<int, int> >::iterator it = pairs.begin();
				std::advance(it, k);
				std::list<int>::iterator bound = std::find(mainChain.begin(), mainChain.end(), it->second);
				std::list<int>::iterator insert_pos = std::lower_bound(mainChain.begin(), bound, it->first);
				mainChain.insert(insert_pos, it->first);
			}
		}
		i++;
	}
}

void	sortList(std::list<int> &container)
{
	if (container.size() <= 1) return ;

	std::list<std::pair<int, int> >	pairs = breakSortList(container, container.size());
	std::list<int>						largerElements;
	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
		largerElements.push_back((*it).second);

	sortList(largerElements);

	std::list<std::pair<int, int> > sortedPairs;
	for (std::list<int>::iterator lit = largerElements.begin(); lit != largerElements.end(); ++lit)
	{
		for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
		{
			if (it->second == *lit)
			{
				sortedPairs.push_back(*it);
				pairs.erase(it);
				break;
			}
		}
	}
	pairs = sortedPairs;
	std::cout << "Pairs: " << std::endl;
	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
		std::cout << it->first << " " << it->second << std::endl;

	std::list<int>						mainChain = largerElements;
	binaryInsertList(mainChain, pairs);

	if (container.size() % 2 != 0)
	{
		std::list<int>::iterator insert_pos = std::lower_bound(mainChain.begin(), mainChain.end(), container.back());
		mainChain.insert(insert_pos, container.back());
	}

	container.clear();
	container = mainChain;
}

// Full constructor
PmergeMe::PmergeMe(std::string &input)
{
	std::string::iterator	it = input.begin();
	std::string::iterator	it2 = input.begin();

	parseInput(this->_cnt1, it, it2, input.end());

	clock_t	start = clock();
	std::copy(this->_cnt1.begin(), this->_cnt1.end(), std::back_inserter(this->_cnt2));
	sortDeque(this->_cnt2);
	clock_t	end = clock();
	this->_stopWatchDeque = static_cast<double>(end - start);

	start = clock();
	std::copy(this->_cnt1.begin(), this->_cnt1.end(), std::back_inserter(this->_cnt3));
	sortList(this->_cnt3);
	end = clock();
	this->_stopWatchList = static_cast<double>(end - start);

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
	std::cout << "Before: ";
	int count = 0;
	while (it != ite && count < 5)
	{
		std::cout << *it << " ";
		it++;
		count++;
	}
	if (it != ite) std::cout << "[...]";
	std::cout << std::endl;
	
	std::cout << "After: ";
	it = this->_cnt2.begin();
	ite = this->_cnt2.end();
	count = 0;
	while (it != ite && count < 5)
	{
		std::cout << *it << " ";
		it++;
		count++;
	}
	if (it != ite)
		std::cout << "[...]";
	std::cout << std::endl;
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
