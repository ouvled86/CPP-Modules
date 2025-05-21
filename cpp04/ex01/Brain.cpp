#include "Brain.hpp"

// Default constructor
Brain::Brain(void)
{
	std::cout << "Brain's default constructor called" << std::endl;
	this->size = 0;
	return ;
}

// Copy constructor
Brain::Brain(const Brain &other)
{
	std::cout << "Brain's copy constructor called" << std::endl;
	this->size = other.size;
	for (int i = 0; i < this->size; i++)
		this->addIdea(other.getIdea(i));
	return ;
}

// Assignment operator overload
Brain	&Brain::operator=(const Brain &other)
{
	std::cout << "Brain's assignment operator called" << std::endl;
	if (this != &other)
	{
		this->size = other.size;
		for (int i = 0; i < this->size; i++)
			this->addIdea(other.getIdea(i));
	}
	return (*this);
}

// Destructor
Brain::~Brain(void)
{
	std::cout << "Brain's destructor called" << std::endl;
	return ;
}

void	Brain::addIdea(const std::string& idea)
{
	this->ideas[this->size] = idea;
	this->size++;
}

const std::string&	Brain::getIdea(int index) const
{
	if (index >= this->size)
		return ("N/A");
	return (this->ideas[index]);
}

const int&	Brain::getSize() const
{
	return (this->size);
}
