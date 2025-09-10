/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:43:30 by ouvled            #+#    #+#             */
/*   Updated: 2025/09/10 20:38:18 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <string>
# include <stack>
# include <cstdlib>

class RPN
{
public:
	RPN(void);
	RPN(std::string &expr);
	RPN(const RPN& other);
	~RPN();
	RPN					&operator=(const RPN &other);
	void				evaluate(void);
	void				printResult(void) const;
private:
	std::string			_expr;
	std::stack<double>	_ctr;
	double				_result;
	bool				_errFlag;
};

bool					badInput(std::string &input);
double					calculate(double oprd1, double oprd2, char oprt);

#endif
