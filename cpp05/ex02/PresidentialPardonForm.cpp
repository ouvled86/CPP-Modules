#include "PresidentialPardonForm.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential Pardon", 25, 5)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

// Named constructor
PresidentialPardonForm::PresidentialPardonForm(std::string Target) : AForm("Presidential Pardon", 25, 5), target(Target)
{
	std::cout << "Named constructor called" << std::endl;
	return ;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm("Presidential Pardon", 25, 5)
{
	std::cout << "Copy constructor called" << std::endl;
	(void) other;
	return ;
}

// Assignment operator overload
PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "Assignment operator called" << std::endl;
	(void) other;
	return (*this);
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	if (this->getExecGrade() > executor.getGrade())
		throw AForm::GradeTooLowException();
	if (this->getIsSigned())
		throw AForm::FormNotSigned();
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
