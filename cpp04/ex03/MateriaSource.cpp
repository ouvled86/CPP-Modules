#include "MateriaSource.hpp"

// Default constructor
MateriaSource::MateriaSource(void)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "Copy constructor called" << std::endl;
	(void) other;
	return ;
}

// Assignment operator overload
MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "Assignment operator called" << std::endl;
	(void) other;
	return (*this);
}

// Destructor
MateriaSource::~MateriaSource(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

