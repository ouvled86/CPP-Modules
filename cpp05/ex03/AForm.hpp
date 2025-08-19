#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	name;
	bool				isSigned;
	const int			signGrade;
	const int			execGrade;

public:
	AForm(void);
	AForm(std::string Name, int SignGrade, int ExecGrade);
	AForm(const AForm& other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class FormNotSigned : public std::exception
	{
		virtual const char* what() const throw();
	};
	const std::string	&getName( void ) const;
	bool				getIsSigned( void ) const;
	int					getSignGrade( void ) const;
	int					getExecGrade( void ) const;
	void				beSigned( Bureaucrat &brct );
	virtual void		execute(Bureaucrat const & executor) const = 0;
};
std::ostream&			operator<<(std::ostream& COUT, AForm &form);

#endif

