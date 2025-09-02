/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:28:42 by ouvled            #+#    #+#             */
/*   Updated: 2025/09/02 19:20:10 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>
# include <vector>
# include <iterator>

template < typename T >
class MutantStack : public std::stack< T >
{
public:
	MutantStack(void) {}
	MutantStack(const MutantStack &original) { this->c(original.c); }
	~MutantStack() {}
	MutantStack												&operator=(const MutantStack &original) { this->c = original.c; }

	typedef typename std::deque<T>::reverse_iterator		iterator;
	typedef typename std::deque<T>::iterator				reverse_iterator;
	typedef typename std::deque<T>::const_reverse_iterator	const_iterator;
	typedef typename std::deque<T>::const_iterator			const_reverse_iterator;

	iterator												begin() { return this->c.rbegin(); }
	iterator												end() { return this->c.rend(); }
	reverse_iterator										rbegin() { return this->c.begin(); }
	reverse_iterator										rend() { return this->c.end(); }
};

#endif