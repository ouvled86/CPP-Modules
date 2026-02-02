/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 19:03:12 by ouvled            #+#    #+#             */
/*   Updated: 2026/02/02 03:01:35 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template < typename T >
void	swap(T &a, T &b)
{
	T	holder = a;
	a = b;
	b = holder;
}

template < typename T >
T const	&min(T const &a, T const &b)
{
	if (a >= b)
		return b;
	return a;
}

template < typename T >
T const	&max(T const &a, T const &b)
{
	if (b > a)
		return b;
	return a;
}

#endif