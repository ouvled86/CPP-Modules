/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:09:22 by ouvled            #+#    #+#             */
/*   Updated: 2026/01/21 01:31:39 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() { return; }

Base	*generate(void)
{
	static bool	run_flag = false;
	int			ranval;
	Base		*ret;

	if (!run_flag)
	{
		srand(static_cast<unsigned int>(time(0)));
		run_flag = true;
	}
	ranval = rand() % 3;
	switch (ranval)
	{
		case 0:
		{
			std::cout << "Returning an A class" << std::endl;
			ret = new A();
			break ;
		}
		case 1:
		{
			std::cout << "Returning a B class" << std::endl;
			ret = new B();
			break ;
		}
		case 2:
		{
			std::cout << "Returning a C class" << std::endl;
			ret = new C();
			break ;
		}
	}
	return (ret);
}

void	identify(Base *p)
{
	A	*one = NULL;
	B	*two = NULL;
	C	*three = NULL;

	one = dynamic_cast<A *>(p);
	
	if (one)
	{
		std::cout << "The actual type of p is class A!" << std::endl;
		return ;
	}
	two = dynamic_cast<B *>(p);
	if (two)
	{
		std::cout << "The actual type of p is class B!" << std::endl;
		return ;
	}
	three = dynamic_cast<C *>(p);
	if (three)
	{
		std::cout << "The actual type of p is class C!" << std::endl;
		return ;
	}
	std::cout << "Type is unknown!" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A	&holder = dynamic_cast<A &>(p);
		(void) holder;
		std::cout << "The actual type of p is class A!" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}

	try
	{
		B	&holder = dynamic_cast<B &>(p);
		(void) holder;
		std::cout << "The actual type of p is class B!" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}

	try
	{
		C	&holder = dynamic_cast<C &>(p);
		(void) holder;
		std::cout << "The actual type of p is class C!" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	std::cout << "Type is unknown!" << std::endl;
	return;
}
