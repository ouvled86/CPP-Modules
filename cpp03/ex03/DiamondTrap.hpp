#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include <iostream>
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string	Name;

public:
	DiamondTrap(void);
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& other);
	DiamondTrap	&operator=(const DiamondTrap &other);
	~DiamondTrap();
	void		whoAmI(void);
	void		attack(const std::string& target);
	void		attack(ClapTrap& target);
};

#endif
