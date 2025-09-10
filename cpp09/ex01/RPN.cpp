/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:43:04 by ouvled            #+#    #+#             */
/*   Updated: 2025/09/10 20:39:21 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Default constructor
RPN::RPN(void)
{
	return ;
}

// Full constructor
RPN::RPN(std::string &expr) : _expr(expr), _errFlag(false)
{
	return ;
}

// Copy constructor
RPN::RPN(const RPN &other)
{
	(void) other;
	return ;
}

// Destructor
RPN::~RPN(void)
{
	return ;
}

// Assignment operator overload
RPN	&RPN::operator=(const RPN &other)
{
	(void) other;
	return (*this);
}

void	RPN::evaluate(void)
{
	for (std::string::iterator it = this->_expr.begin(); it != this->_expr.end(); it++)
	{
		if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
		{
			if (this->_ctr.size() > 1)
			{
				int	secondVal = this->_ctr.top();
				this->_ctr.pop();
				int	firstVal = this->_ctr.top();
				int	newVal = calculate(firstVal, secondVal, *it);
				this->_ctr.pop();
				this->_ctr.push(newVal);
			}
			else
			{
				this->_errFlag = true;
				return ;
			}
		}
		else if (isdigit (*it))
			this->_ctr.push(*it - '0');
	}
	if (this->_ctr.size() != 1)
	{
		this->_errFlag = true;
		return ;
	}
	this->_result = this->_ctr.top();
}

void	RPN::printResult(void) const
{
	if (this->_errFlag)
	{
		std::cerr << "Error: bad input." << std::endl;
		exit (201);
	}
	std::cout << this->_result << std::endl;
}

bool	badInput(std::string &input)
{
	if (*(input.end() - 1) == ' ')
		return (true);
	for (std::string::iterator it = input.begin(); it != input.end(); it++)
	{
		if (*it != '+' && *it != '-' && *it != '*' && *it != '/' && !isdigit(*it))
			return (true);
		it++;
		if (it != input.end() && *it != ' ')
		{
			std::cout << *it << std::endl;
			return (true);
		}
		if (it == input.end())
			break ;
	}
	return (false);
}

double	calculate(double oprd1, double oprd2, char oprt)
{
	switch (oprt) {
		case '+':
			return oprd1 + oprd2;
		case '-':
			return oprd1 - oprd2;
		case '*':
			return oprd1 * oprd2;
		case '/':
			return oprd1 / oprd2;
	}
	return 0;
}
