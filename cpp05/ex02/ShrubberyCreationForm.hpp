#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string	target;

public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string Target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();
	void					execute(Bureaucrat const & executor) const;
};

#endif

