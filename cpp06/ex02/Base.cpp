/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:09:22 by ouvled            #+#    #+#             */
/*   Updated: 2025/08/24 20:09:57 by ouvled           ###   ########.fr       */
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
	// A	one;
	// B	two;
	// C	three;

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
			std::cout << "Returning an B class" << std::endl;
			ret = new B();
			break ;
		}
		case 2:
		{
			std::cout << "Returning an C class" << std::endl;
			ret = new C();
			break ;
		}
	}
	return (ret);
}

void	identify(Base *p)
{
	A	*one;
	B	*two;
	C	*three;

	one = dynamic_cast<A *>(p);
	two = dynamic_cast<B *>(p);
	three = dynamic_cast<C *>(p);
	
	if (one)
		std::cout << "The actual type of p is class A!" << std::endl;
	else if (two)
		std::cout << "The actual type of p is class B!" << std::endl;
	else if (three)
		std::cout << "The actual type of p is class C!" << std::endl;
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
}
