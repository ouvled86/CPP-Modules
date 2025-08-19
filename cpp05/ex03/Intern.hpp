#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	Intern(void);
	Intern(const Intern& other);
	Intern	&operator=(const Intern &other);
	~Intern();
	class InvalidFormName : public std::exception
	{
		virtual const char* what() const throw();
	};
	AForm	*makeForm(std::string name, std::string target);
};

#endif

