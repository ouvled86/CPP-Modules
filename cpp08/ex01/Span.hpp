#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>

class Span
{
public:
	Span(void);
	Span(unsigned int N);
	Span(const Span& other);
	~Span();
	Span				&operator=(const Span &other);
	void				addNumber(int num);
	int					shortestSpan(void);
	int					longestSpan(void) const;
	template < typename T >
	void				addRange(T start, T end)
	{
		while (start < end) 
		{
			addNumber(*start);
			start++;
		}
	}
private:
	std::vector<int>	_cnt;
	unsigned int		_size;
	unsigned int		_current_size;
	int					_max;
	int					_min;
	bool				_dirty;
};

#endif

