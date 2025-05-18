#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
#include <string>

class ClapTrap
{
protected:
	std::string	Name;
	std::string	Type;
	int			HitPts;
	int			EnergyPts;
	int			AttackDmg;

public:
	ClapTrap(void);
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& other);
	ClapTrap	&operator=(const ClapTrap &other);
	~ClapTrap();
	void		attack(const std::string& target);
	void		attack(ClapTrap& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
};

#endif
