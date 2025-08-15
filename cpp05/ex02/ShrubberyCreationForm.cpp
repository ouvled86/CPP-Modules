#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Creation", 145, 137)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

// Named constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string Target) : AForm("Shrubbery Creation", 145, 137), target(Target)
{
	std::cout << "Named constructor called" << std::endl;
	return ;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm("Shrubbery Creation", 145, 137)
{
	std::cout << "Copy constructor called" << std::endl;
	(void) other;
	return ;
}

// Assignment operator overload
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "Assignment operator called" << std::endl;
	(void) other;
	return (*this);
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	if (this->getExecGrade() > executor.getGrade())
		throw AForm::GradeTooLowException();
	if (this->getIsSigned())
		throw AForm::FormNotSigned();
	std::string		fname = this->target + "_shrubbery";
	std::ofstream	file(fname.c_str());
	if (!file) {
		std::cerr << "File creation failure\n";
		return ;
	}
	    file <<
"          &&& &&  & &&\n"
"      && &\\/&\\|& ()|/ @, &&\n"
"      &\\/(/&/&||/& /_/)_&/_&\n"
"   &() &\\/&|()|/&\\/ '%\" & ()\n"
"  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
"&&   && & &| &| /& & % ()& /&&\n"
" ()&_---()&\\&\\|&&-&&--%---()~\n"
"     &&     \\|||\n"
"             |||\n"
"             |||\n"
"             |||\n"
"       , -=-~  .-^- _\n";
    file.close();
}
