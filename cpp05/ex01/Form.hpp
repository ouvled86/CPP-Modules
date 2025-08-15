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
	Form(std::string Name, int SignGrade, int ExecGrade);
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
	const std::string	&getName( void );
	bool				getIsSigned( void );
	int					getSignGrade( void );
	int					getExecGrade( void );
	void				beSigned( Bureaucrat &brct );
};
std::ostream&			operator<<(std::ostream& COUT, Form &form);

#endif

