#include "ScavTrap.hpp"
#include <iostream>

// Default constructor
ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap's default constructor called" << std::endl;
	this->Name = "N/A";
	this->Type = "ScavTrap";
	this->HitPts = 100;
	this->EnergyPts = 50;
	this->AttackDmg = 20;
	return ;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScavTrap's named constructor called" << std::endl;
	this->Type = "ScavTrap";
	this->HitPts = 100;
	this->EnergyPts = 50;
	this->AttackDmg = 20;
	return ;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other.Name)
{
	std::cout << "ScavTrap's copy constructor called" << std::endl;
	this->Type = other.Type;
	this->HitPts = other.HitPts;
	this->EnergyPts = other.EnergyPts;
	this->AttackDmg = other.AttackDmg;
	return ;
}

// Assignment operator overload
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap's assignment operator called" << std::endl;
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
ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap's destructor called" << std::endl;
	return ;
}

void	ScavTrap::guardGate()
{
	std::cout << this->Type << " " << this->Name << " is now in gate keeper mode" << '\n';
	return ;
}
