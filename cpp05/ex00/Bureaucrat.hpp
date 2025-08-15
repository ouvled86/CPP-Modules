/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:10:31 by ouvled            #+#    #+#             */
/*   Updated: 2025/08/14 11:10:32 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Bureaucrat
{
private:
	const std::string	name;
	int					grade;

public:
	Bureaucrat(void);
	Bureaucrat(std::string Name, int Grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat			&operator=(const Bureaucrat &other);
	~Bureaucrat();
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
	const std::string	&getName( void );
	int					getGrade( void );
	void				incrementGrade( int amount );
	void				decrementGrade( int amount );
};
std::ostream&			operator<<(std::ostream& COUT, Bureaucrat &brct);

#endif
