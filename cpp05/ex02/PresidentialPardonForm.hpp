#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string	target;
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string Target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm	&operator=(const PresidentialPardonForm &other);
	~PresidentialPardonForm();
	void					execute(Bureaucrat const & executor) const;
};

#endif

