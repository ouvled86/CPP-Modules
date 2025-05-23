#include "Cure.hpp"

// Default constructor
Cure::Cure(void) : AMateria("ice")
{
	std::cout << "Cure's default constructor called" << std::endl;
	return ;
}

// Copy constructor
Cure::Cure(const Cure &other) : AMateria("ice")
{
	std::cout << "Cure's copy constructor called" << std::endl;
	(void) other;
	return ;
}

// Assignment operator overload
Cure	&Cure::operator=(const Cure &other)
{
	std::cout << "Cure's assignment operator called" << std::endl;
	(void) other;
	return (*this);
}

// Destructor
Cure::~Cure(void)
{
	std::cout << "Cure's destructor called" << std::endl;
	return ;
}

Cure	*Cure::clone() const
{
	return (new Cure);
}
