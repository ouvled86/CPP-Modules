/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:10:35 by ouvled            #+#    #+#             */
/*   Updated: 2025/08/14 11:38:24 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat(void) : name("N/A"), grade(150)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

// Named constructor
Bureaucrat::Bureaucrat(std::string Name, int Grade) : name(Name)
{
	std::cout << "Named constructor called" << std::endl;
	if (Grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (Grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade = Grade;
	return ;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

// Assignment operator overload
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Assignment operator called" << std::endl;
	this->grade = other.grade;
	return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Exception: the grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Exception: the grade is too low!");
}

const std::string	&Bureaucrat::getName( void )
{
	return (this->name);
}

int	Bureaucrat::getGrade( void )
{
	return (this->grade);
}

void	Bureaucrat::incrementGrade( int amount )
{
	if (this->grade - amount < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade -= amount;
}

void	Bureaucrat::decrementGrade( int amount )
{
	if (this->grade + amount > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade += amount;
}

std::ostream&	operator<<(std::ostream& COUT, Bureaucrat &brct)
{
	COUT << brct.getName() << ", bureaucrat grade " << brct.getGrade();
	return COUT;
}