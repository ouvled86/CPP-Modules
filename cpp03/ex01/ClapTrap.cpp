#include "ClapTrap.hpp"
#include <iostream>

// Default constructor
ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap's default constructor called" << std::endl;
	this->Name = "N/A";
	this->Type = "ClapTrap";
	this->HitPts = 10;
	this->EnergyPts = 10;
	this->AttackDmg = 0;
	return ;
}

ClapTrap::ClapTrap(const std::string& name)
{
	std::cout << "ClapTrap's named constructor called" << std::endl;
	this->Name = name;
	this->Type = "ClapTrap";
	this->HitPts = 10;
	this->EnergyPts = 10;
	this->AttackDmg = 0;
	return ;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other) : Name(other.Name)
{
	std::cout << "ClapTrap's copy constructor called" << std::endl;
	this->Type = other.Type;
	this->HitPts = other.HitPts;
	this->EnergyPts = other.EnergyPts;
	this->AttackDmg = other.AttackDmg;
	return ;
}

// Assignment operator overload
ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap's assignment operator called" << std::endl;
	this->Name = other.Name;
	this->Type = other.Type;
	this->HitPts = other.HitPts;
	this->EnergyPts = other.EnergyPts;
	this->AttackDmg = other.AttackDmg;
	return (*this);
}

// Destructor
ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap's destructor called" << std::endl;
	return ;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->EnergyPts > 0)
	{
		std::cout << this->Type << " " << this->Name << " attacks " << target << ", causing " << this->AttackDmg << " points of damage!" << '\n';
		this->EnergyPts--;
	}
	else
		std::cout << this->Type << " " << this->Name << " doesn't have enough energy points to attack " << target << '!' << '\n';
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->HitPts > 0)
	{
		std::cout << this->Type << " " << this->Name << " takes " << amount << " amount of damage!" << '\n';
		this->HitPts -= amount;
	}
	else
		std::cout << this->Type << " " << this->Name << " is already destroyed and can't take any damage!" << '\n';
	return ;
}

void	ClapTrap::attack(ClapTrap& target)
{
	if (this->HitPts <= 0)
	{
		std::cout << this->Type << " " << this->Name << " is destroyed and can't attack target: " << target.Name << '!' << '\n';
		return ;
	}
	if (this->EnergyPts > 0 && target.HitPts > 0)
	{
		std::cout << this->Type << " " << this->Name << " attacks " << target.Name << ", causing " << this->AttackDmg << " points of damage!" << '\n';
		target.takeDamage(this->AttackDmg);
		this->EnergyPts--;
	}
	else if (target.HitPts <= 0)
		std::cout << this->Type << " " << this->Name << " tries to attack " << target.Name << " only to find that it is already destroyed, what an easy target!" << '\n';
	else
		std::cout << this->Type << " " << this->Name << " doesn't have enough energy points to attack " << target.Name << '!' << '\n';
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->HitPts <= 0)
	{
		std::cout << this->Type << " " << this->Name << " is destroyed and can't repair itself!" << '\n';
		return ;
	}
	if (this->EnergyPts > 0)
	{
		std::cout << this->Type << " " << this->Name << " has repaired itself and gained " << amount << " amount of hit points!" << '\n';
		this->EnergyPts--;
		this->HitPts += amount;
	}
	else
		std::cout << this->Type << " " << this->Name << " doesn't have enough energy points to repair itself!" << '\n';
	return ;
}

