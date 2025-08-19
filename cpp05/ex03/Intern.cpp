#include "Intern.hpp"

// Default constructor
Intern::Intern(void)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

// Copy constructor
Intern::Intern(const Intern &other)
{
	std::cout << "Copy constructor called" << std::endl;
	(void) other;
	return ;
}

// Assignment operator overload
Intern	&Intern::operator=(const Intern &other)
{
	std::cout << "Assignment operator called" << std::endl;
	(void) other;
	return (*this);
}

// Destructor
Intern::~Intern(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

const char	*Intern::InvalidFormName::what() const throw()
{
	return ("Invalid form name. Available forms:\n - Presidential Pardon Form\n - Robotomy Request Form\n - Shrubbery Creation Form");
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	std::string	forms[3] = { "presidential pardon", "robotomy request", "shrubbery creation"};
	AForm		*ret = NULL;
	int			i = 0;

	try
	{
		while (i < 3)
		{
			if (forms[i] == name)
			{
				switch (i)
				{
					case 0:
					{
						ret = new PresidentialPardonForm(target);
						break ;
					}
					case 1:
					{
						ret = new RobotomyRequestForm(target);
						break ;
					}
					case 2:
					{
						ret = new ShrubberyCreationForm(target);
						break ;
					}
				}
				std::cout << "Intern creates a " << name << " form" << std::endl;
				return (ret);
			}
		i++;
		}
		throw Intern::InvalidFormName();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (ret);
}

