#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <string>
# include <deque>
# include <list>

class PmergeMe
{
public:
	PmergeMe(void);
	PmergeMe(std::deque<int> cnt);
	PmergeMe(std::string &input);
	PmergeMe(const PmergeMe& other);
	~PmergeMe();
	PmergeMe		&operator=(const PmergeMe &other);
	void			printInfo(void);
	std::deque<int>	getCnt1(void) { return this->_cnt1; }
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
void				sortDeque(std::deque<int> &container);
void				sortList(std::list<int> &container);

#endif

