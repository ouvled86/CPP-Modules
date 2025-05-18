#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap(void)
{
	std::cout << "Diamond Trap's default constructor called" << std::endl;
	this->Name = "N/A";
	this->Type = "DiamondTrap";
	this->HitPts = 100;
	this->EnergyPts = 50;
	this->AttackDmg = 30;
	return ;
}

// Named constructor
DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "Diamond Trap's named constructor called" << std::endl;
	this->Name = name;
	this->Type = "DiamondTrap";
	this->HitPts = 100;
	this->EnergyPts = 50;
	this->AttackDmg = 30;
	return ;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other.Name + "_clap_name"), ScavTrap(other.Name), FragTrap(other.Name)
{
	std::cout << "Diamond Trap's copy constructor called" << std::endl;
	(void)other;
	this->Name = other.Name;
	this->Type = "DiamondTrap";
	this->HitPts = other.HitPts;
	this->EnergyPts = other.EnergyPts;
	this->AttackDmg = other.AttackDmg;
	return ;
}

// Assignment operator overload
DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "Diamond Trap's assignment operator called" << std::endl;
	if (this != &other)
	{
		this->Name = other.Name;
		this->ClapTrap::Name = other.Name + "_clap_name";
		this->Type = "DiamondTrap";
		this->HitPts = other.HitPts;
		this->EnergyPts = other.EnergyPts;
		this->AttackDmg = other.AttackDmg;
	}
	return (*this);
}

// Destructor
DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Diamond Trap's destructor called" << std::endl;
	return ;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "Hey hey! I'm a Diamond Trap, they call me " << this->Name << " AKA " << this->ClapTrap::Name << '!' << std::endl;
	return ;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
	return ;
}

void	DiamondTrap::attack(ClapTrap& target)
{
	ScavTrap::attack(target);
	return ;
}
