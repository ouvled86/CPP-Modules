/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:11:33 by ouvled            #+#    #+#             */
/*   Updated: 2025/08/27 19:11:46 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template < typename T >
void	iter(T *arr, size_t len, void func(T &))
{
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}

template < typename T >
void	iter(const T *arr, size_t len, void func(const T &))
{
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}

#endif