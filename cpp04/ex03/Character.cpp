#include "Character.hpp"

// Default constructor
Character::Character(void) : Name("N/A")
{
	// std::cout << "Character's default constructor called" << std::endl;
	// std::cout << "Address of Slots[0] is: " << this->Slots[0] << std::endl;
	for (int i = 0; i < 4; i++)
		this->Slots[i] = NULL;
	col	= NULL;
	// std::cout << "After assignment. Address of Slots[0] is: " << this->Slots[0] << std::endl;
	return ;
}

Character::Character(std::string const& name) : Name(name)
{
	// std::cout << "Character's default constructor called" << std::endl;
	col	= NULL;
	return ;
}

// Copy constructor
Character::Character(const Character &other) : Name(other.Name)
{
	// std::cout << "Character's copy constructor called" << std::endl;
	col	= NULL;
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
	// std::cout << "Character's assignment operator called" << std::endl;
	col	= NULL;
	if (this != &other)
	{
		this->Name = other.Name;
		for (int i = 0; i < 4; i++)
		{
			if (this->Slots[i])
			{
				delete this->Slots[i];
				this->Slots[i] = NULL;
			}
			if (other.Slots[i])
				this->Slots[i] = other.Slots[i]->clone();
		}
	}
	return (*this);
}

// Destructor
Character::~Character(void)
{
	// std::cout << "Character's destructor called" << std::endl;
	this->freeMemory();
	return ;
}

std::string const&	Character::getName() const
{
	return (this->Name);
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->Slots[i])
		{
			this->Slots[i] = m;
			break ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (this->Slots[idx])
	{
		this->insertNode(this->Slots[idx]);
		this->Slots[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (this->Slots[idx])
		this->Slots[idx]->use(target);
}

void	Character::insertNode(AMateria *m)
{
	Node	*tmp = this->col;

	while (tmp)
		tmp = tmp->next;
	tmp = new Node;
	tmp->m = m;
	tmp->next = NULL;
}

void	Character::freeMemory(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->Slots[i])
			delete this->Slots[i];
	}
	Node	*tmp;
	while(this->col)
	{
		delete this->col->m;
		tmp = this->col;
		this->col = this->col->next;
		delete tmp;
	}
}
