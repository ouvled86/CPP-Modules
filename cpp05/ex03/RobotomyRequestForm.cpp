#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

// Default constructor
RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Request", 72, 45)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

// Named constructor
RobotomyRequestForm::RobotomyRequestForm(std::string Target) : AForm("Robotomy Request", 72, 45), target(Target)
{
	std::cout << "Named constructor called" << std::endl;
	return ;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm("Robotomy Request", 72, 45)
{
	std::cout << "Copy constructor called" << std::endl;
	(void) other;
	return ;
}

// Assignment operator overload
RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "Assignment operator called" << std::endl;
	(void) other;
	return (*this);
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	if (this->getExecGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();
	if (!this->getIsSigned())
		throw AForm::FormNotSigned();
	static bool	seedBool = false;
	if (!seedBool)
	{
		std::srand(std::time(0));
		seedBool = true;
	}
	std::cout << "* drilling noises *" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << this->target << " robotomy failed!" << std::endl;
}
