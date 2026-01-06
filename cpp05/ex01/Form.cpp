#include "Form.hpp"

// Default constructor
Form::Form(void) : name("Unnamed"), isSigned(0), signGrade(150), execGrade(150)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

// Named Constructor
Form::Form(const std::string &Name, int SignGrade, int ExecGrade) : name(Name), signGrade(SignGrade), execGrade(ExecGrade)
{
	std::cout << "Named constructor called" << std::endl;
	if (SignGrade < 1 || ExecGrade < 1)
		throw Form::GradeTooHighException();
	if (SignGrade > 150 || ExecGrade > 150)
		throw Form::GradeTooLowException();
	return ;
}

// Copy constructor
Form::Form(const Form &other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade)
{
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

// Assignment operator overload
Form	&Form::operator=(const Form &other)
{
	std::cout << "Assignment operator called" << std::endl;
	this->isSigned = other.isSigned;
	return (*this);
}

// Destructor
Form::~Form(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Exception: the grade is too high!");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Exception: the grade is too low!");
}

const std::string	&Form::getName( void ) const
{
	return this->name;
}

bool	Form::getIsSigned( void ) const
{
	return this->isSigned;
}

int	Form::getSignGrade( void ) const
{
	return this->signGrade;
}

int	Form::getExecGrade( void ) const
{
	return this->execGrade;
}

void	Form::beSigned( const Bureaucrat &brct )
{
	if (this->signGrade < brct.getGrade())
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

std::ostream&	operator<<(std::ostream& COUT, const Form &form)
{
	if (form.getIsSigned() == true)
		COUT << form.getName() << ", required sign grade is: " << form.getSignGrade() << ", required execution grade is: " << form.getExecGrade() << ", is signed!";
	else
		COUT << form.getName() << ", required sign grade is: " << form.getSignGrade() << ", required execution grade is: " << form.getExecGrade() << ", is not signed!";
	return COUT;
}
