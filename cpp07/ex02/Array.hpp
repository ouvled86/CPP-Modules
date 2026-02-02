/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:42:38 by ouvled            #+#    #+#             */
/*   Updated: 2026/02/02 03:43:32 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{

private:
	T			*addr;
	size_t		_size;

public:
	Array<T>(void)
	{
		addr = NULL;
		this->_size = 0;
	}

	Array<T>(unsigned int n)
	{
		addr = new T[n];
		_size = static_cast<size_t>(n);
		for (size_t i = 0; i < n; i++)
			addr[i] = T();
	}

	Array<T>(const Array<T> &other)
	{
		if (other._size)
		{
			this->addr = new T[other._size];
			for (size_t i = 0; i < other._size; i++)
				this->addr[i] = other.addr[i];
			this->_size = other._size;
		}
		else
		{
			this->addr = NULL;
			this->_size = 0;
		}
	}

	Array<T>	&operator=(const Array<T> &other)
	{
		if (this != &other)
		{
			delete[] this->addr;
			if (other._size)
			{
				this->addr = new T[other._size];
				for (size_t i = 0; i < other._size; i++)
					this->addr[i] = other.addr[i];
				this->_size = other._size;
			}
			else
			{
				this->addr = NULL;
				this->_size = 0;
			}
		}
		return (*this);
	}

	T			&operator[](size_t index)
	{
		if (index >= _size)
			throw std::out_of_range("Index out of bounds");
		return (addr[index]);
	}

	const T		&operator[](size_t index) const
	{
		if (index >= _size)
			throw std::out_of_range("Index out of bounds");
		return (addr[index]);
	}

	~Array<T>()
	{
		if (addr)
			delete[] addr;
	}

	size_t		size(void) const
	{
		return (this->_size);
	}

};

#endif