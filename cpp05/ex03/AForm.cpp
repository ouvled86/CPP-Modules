#include "AForm.hpp"

// Default constructor
AForm::AForm(void) : name("Unnamed"), isSigned(0), signGrade(150), execGrade(150)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

// Named Constructor
AForm::AForm(std::string Name, int SignGrade, int ExecGrade) : name(Name), signGrade(SignGrade), execGrade(ExecGrade)
{
	std::cout << "Named constructor called" << std::endl;
	if (SignGrade < 1 || ExecGrade < 1)
		throw AForm::GradeTooHighException();
	if (SignGrade > 150 || ExecGrade > 150)
		throw AForm::GradeTooLowException();
	return ;
}

// Copy constructor
AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade)
{
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

// Assignment operator overload
AForm	&AForm::operator=(const AForm &other)
{
	std::cout << "Assignment operator called" << std::endl;
	this->isSigned = other.isSigned;
	return (*this);
}

// Destructor
AForm::~AForm(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Exception: the grade is too high!");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Exception: the grade is too low!");
}

const char*	AForm::FormNotSigned::what() const throw()
{
	return ("Exception: this form is not signed!");
}

const std::string	&AForm::getName( void ) const
{
	return this->name;
}

bool	AForm::getIsSigned( void ) const
{
	return this->isSigned;
}

int	AForm::getSignGrade( void ) const
{
	return this->signGrade;
}

int	AForm::getExecGrade( void ) const
{
	return this->execGrade;
}

void	AForm::beSigned( const Bureaucrat &brct )
{
	// std::cout << "Signed grade: " << this->signGrade << "Brct grade: " << brct.getGrade() << std::endl;
	if (this->signGrade < brct.getGrade())
		throw AForm::GradeTooLowException();
	this->isSigned = true;
}

std::ostream&	operator<<(std::ostream& COUT, const AForm &form)
{
	if (form.getIsSigned() == true)
		COUT << form.getName() << ", required sign grade is: " << form.getSignGrade() << ", required execution grade is: " << form.getExecGrade() << ", is signed!" << std::endl;
	else
		COUT << form.getName() << ", required sign grade is: " << form.getSignGrade() << ", required execution grade is: " << form.getExecGrade() << ", is not signed!" << std::endl;
	return COUT;
}
