/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:02:36 by ouvled            #+#    #+#             */
/*   Updated: 2025/09/01 20:33:21 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <vector>
# include <algorithm>
# include <climits>
# include <stdexcept>

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
	void				addRange(std::vector<int>::const_iterator start, std::vector<int>::const_iterator end);
private:
	std::vector<int>	_cnt;
	unsigned int		_size;
	unsigned int		_current_size;
	int					_max;
	int					_min;
	bool				_dirty;
};

#endif

