#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	name;
	bool				isSigned;
	const int			signGrade;
	const int			execGrade;

public:
	Form(void);
	Form(const std::string &Name, int SignGrade, int ExecGrade);
	Form(const Form& other);
	Form &operator=(const Form &other);
	~Form();
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
	const std::string	&getName( void ) const;
	bool				getIsSigned( void ) const;
	int					getSignGrade( void ) const;
	int					getExecGrade( void ) const;
	void				beSigned( const Bureaucrat &brct );
};
std::ostream&			operator<<(std::ostream& COUT, const Form &form);

#endif

