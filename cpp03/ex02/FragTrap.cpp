#include "FragTrap.hpp"

// Default constructor
FragTrap::FragTrap(void)
{
	std::cout << "FragTrap's default constructor called" << std::endl;
	this->Name = "N/A";
	this->Type = "FragTrap";
	this->HitPts = 100;
	this->EnergyPts = 100;
	this->AttackDmg = 30;
	return ;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "FragTrap's named constructor called" << std::endl;
	this->Type = "FragTrap";
	this->HitPts = 100;
	this->EnergyPts = 100;
	this->AttackDmg = 30;
	return ;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other.Name)
{
	std::cout << "FragTrap's copy constructor called" << std::endl;
	this->Type = other.Type;
	this->HitPts = other.HitPts;
	this->EnergyPts = other.EnergyPts;
	this->AttackDmg = other.AttackDmg;
	return ;
}

// Assignment operator overload
FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap's assignment operator called" << std::endl;
	if (this != &other)
	{
		this->Name = other.Name;
		this->Type = other.Type;
		this->HitPts = other.HitPts;
		this->EnergyPts = other.EnergyPts;
		this->AttackDmg = other.AttackDmg;
	}
	return (*this);
}

// Destructor
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap's destructor called" << std::endl;
	return ;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << this->Type << " " << this->Name << " is requesting a high-fives!" << '\n';
	return ;
}
