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
ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
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

void	ScavTrap::attack(const std::string& target)
{
	if (this->HitPts <= 0)
	{
		std::cout << this->Type << " " << this->Name << " is destroyed and can't shoot target: " << target << '!' << '\n';
		return ;
	}
	if (this->EnergyPts > 0)
	{
		std::cout << this->Type << " " << this->Name << " aims at " << target << ", and sprays it with bullets causing " << this->AttackDmg << " points of damage!" << '\n';
		this->EnergyPts--;
	}
	else
		std::cout << this->Type << " " << this->Name << " doesn't have enough energy points to attack " << target << '!' << '\n';
	return ;
}

void	ScavTrap::attack(ScavTrap& target)
{
	if (this->HitPts <= 0)
	{
		std::cout << this->Type << " " << this->Name << " is destroyed and can't shoot target: " << target.Name << '!' << '\n';
		return ;
	}
	if (this->EnergyPts > 0 && target.HitPts > 0)
	{
		std::cout << this->Type << " " << this->Name << " aims at " << target.Name << ", and sprays it with bullets causing " << this->AttackDmg << " points of damage!" << '\n';
		target.takeDamage(this->AttackDmg);
		this->EnergyPts--;
	}
	else if (target.HitPts <= 0)
		std::cout << this->Type << " " << this->Name << " tries to attack " << target.Name << " only to find that it is already destroyed, what an easy target!" << '\n';
	else
		std::cout << this->Type << " " << this->Name << " doesn't have enough energy points to attack " << target.Name << '!' << '\n';
	return ;
}
