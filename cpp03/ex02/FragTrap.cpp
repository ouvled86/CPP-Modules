#include "FragTrap.hpp"

// Default constructor
FragTrap::FragTrap(void)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap &other)
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
FragTrap::~FragTrap(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

