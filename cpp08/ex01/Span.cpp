#include "Span.hpp"

// Default constructor
Span::Span(void) : _size(-1), _current_size(0), _max(INT_MIN), _min(INT_MAX), _dirty(true)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

// Named constructor
Span::Span(unsigned int N) : _size(N), _current_size(0), _max(INT_MIN), _min(INT_MAX), _dirty(true)
{
	std::cout << "Named constructor called" << std::endl;
	_cnt.reserve(N);
	return ;
}

// Copy constructor
Span::Span(const Span &other) : _size(other._size), _current_size(other._current_size), _max(other._max), _min(other._min), _dirty(other._dirty)
{
	std::cout << "Copy constructor called" << std::endl;
	_cnt.reserve(_size);
	_cnt = other._cnt;
	return ;
}

// Destructor
Span::~Span(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

// Assignment operator overload
Span	&Span::operator=(const Span &other)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &other)
	{
		if (other._current_size > this->_size) throw std::length_error("Span capacity exceeded");
		this->_cnt.reserve(other._size);
		this->_cnt = other._cnt;
		this->_current_size = other._current_size;
		this->_size = other._size;
		this->_max = other._max;
		this->_min = other._min;
		this->_dirty = other._dirty;
	}
	return (*this);
}

void	Span::addNumber(int num)
{
	if (_current_size == _size) throw std::length_error("Span capacity exceeded");
	_current_size++;
	if (num > _max) _max = num;
	if (num < _min) _min = num;
	_dirty = true;
	_cnt.push_back(num);
}

int	Span::shortestSpan(void)
{

	if (_current_size < 2) throw std::out_of_range("Not enough elements to compute span");
	if (_dirty)
	{
		std::sort(_cnt.begin(), _cnt.end());
		_dirty = false;
	}
	int	ret = INT_MAX;
	for (std::vector<int>::const_iterator start = _cnt.begin(); start != _cnt.end() - 1; start++)
		if (*(start + 1) - *start < ret)
			ret = *(start + 1) - *start;
	return (ret);
}

int	Span::longestSpan(void) const
{
	if (_current_size < 2) throw std::out_of_range("Not enough elements to compute span");
	return (_max - _min);
}

void	Span::addRange(std::vector<int>::const_iterator start, std::vector<int>::const_iterator end)
{
	while (start < end) 
	{
		addNumber(*start);
		start++;
	}
}
