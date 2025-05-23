#include "Character.hpp"

// Default constructor
Character::Character(void) : Name("N/A")
{
	std::cout << "Character's default constructor called" << std::endl;
	std::cout << "Address of Slots[0] is: " << this->Slots[0] << std::endl;
	for (int i = 0; i < 4; i++)
		this->Slots[i] = NULL;
	std::cout << "After assignment. Address of Slots[0] is: " << this->Slots[0] << std::endl;
	return ;
}

Character::Character(std::string const& name) : Name(name)
{
	std::cout << "Character's default constructor called" << std::endl;
	return ;
}

// Copy constructor
Character::Character(const Character &other) : Name(other.Name)
{
	std::cout << "Character's copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other.Slots[i])
			this->Slots[i] = other.Slots[i]->clone();
		else
			this->Slots[i] = NULL;
	}
	return ;
}

// Assignment operator overload
Character	&Character::operator=(const Character &other)
{
	std::cout << "Character's assignment operator called" << std::endl;
	if (this != &other)
	{

	}
	return (*this);
}

// Destructor
Character::~Character(void)
{
	std::cout << "Character's destructor called" << std::endl;
	return ;
}

