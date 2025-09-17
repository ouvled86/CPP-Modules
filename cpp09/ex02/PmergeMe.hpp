/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 16:29:46 by ouvled            #+#    #+#             */
/*   Updated: 2025/09/16 17:08:29 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <deque>
# include <list>
// # include <utility> 
# include <climits>
# include <cstdlib>

class PmergeMe
{
public:
	PmergeMe(void);
	PmergeMe(std::string &input);
	PmergeMe(const PmergeMe& other);
	~PmergeMe();
	PmergeMe		&operator=(const PmergeMe &other);
	void			sortDeque(void);
	void			sortList(void);
	void			printInfo(void);
private:
	std::deque<int>	_cnt1;
	std::deque<int>	_cnt2;
	std::list<int>	_cnt3;
	double			_stopWatchDeque;
	double			_stopWatchList;
};

std::string			mergeInput(char **av, int count);
bool				badInput(std::string::iterator it, std::string::iterator it2);
void				parseInput(std::deque<int> &cnt, std::string::iterator it, std::string::iterator it2, std::string::iterator ite);

#endif

