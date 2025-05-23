#include "AMateria.hpp"

// Default constructor
AMateria::AMateria(void) : Type("N/A")
{
	std::cout << "AMateria's default constructor called" << std::endl;
	return ;
}

AMateria::AMateria(std::string const& type) : Type(type)
{
	std::cout << "AMateria's named constructor called" << std::endl;
	return ;
}

// Copy constructor
AMateria::AMateria(const AMateria &other) : Type(other.type)
{
	std::cout << "AMateria's copy constructor called" << std::endl;
	(void) other;
	return ;
}

// Assignment operator overload
AMateria	&AMateria::operator=(const AMateria &other)
{
	std::cout << "AMateria's assignment operator called" << std::endl;
	this->Type = other.Type;
	return (*this);
}

// Destructor
AMateria::~AMateria(void)
{
	std::cout << "AMateria's destructor called" << std::endl;
	return ;
}

std::string const & AMateria::getType() const
{
	return(this->Type);
}

