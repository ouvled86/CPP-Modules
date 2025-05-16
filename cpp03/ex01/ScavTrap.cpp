#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

// Default constructor
ScavTrap::ScavTrap(void) : ClapTrap(void)
{
  std::cout << "Derived class' default constructor called" << std::endl;
  return ;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other.Name)
{
  std::cout << "Named constructor called" << std::endl;
  this->Name = name;
  this->HitPts = 10;
  this->EnergyPts = 10;
  this->AttackDmg = 0;
  return ;
}

// Copy constructor
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
  std::cout << "Copy constructor called" << std::endl;
  this->HitPts = other.HitPts;
  this->EnergyPts = other.EnergyPts;
  this->AttackDmg = other.AttackDmg;
  return ;
}

// Assignment operator overload
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "Assignment operator called" << std::endl;
  this->Name = other.Name;
  this->HitPts = other.HitPts;
  this->EnergyPts = other.EnergyPts;
  this->AttackDmg = other.AttackDmg;
  return (*this);
}

// Destructor
ScavTrap::~ScavTrap(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

void  ClapTrap::attack(const std::string& target)
{
  if (this->EnergyPts > 0)
  {
    std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDmg << " points of damage!" << '\n';
    this->EnergyPts--;
  }
  else {
    std::cout << "ClapTrap " << this->Name << " doesn't have enough energy points to attack " << target << '!' << '\n';
  }
  return ;
}

void  ClapTrap::takeDamage(unsigned int amount)
{
  if (this->HitPts > 0)
  {
    std::cout << "ClapTrap " << this->Name << " takes " << amount << " amount of damage!" << '\n';
    this->HitPts -= amount;
  }
  else {
    std::cout << "ClapTrap " << this->Name << " is already destroyed and can't take any damage!" << '\n';
  }
  return ;
}

void  ClapTrap::beRepaired(unsigned int amount)
{
  if (this->EnergyPts > 0)
  {
    std::cout << "ClapTrap " << this->Name << " has repaired itself and gained " << amount << " amount of hit points!" << '\n';
    this->EnergyPts--;
    this->HitPts += amount;
  }
  else {
    std::cout << "ClapTrap " << this->Name << " doesn't have enough energy points to repair itself!" << '\n';
  }
  return ;
}

