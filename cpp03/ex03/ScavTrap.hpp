#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& other);
	ScavTrap	&operator=(const ScavTrap &other);
	~ScavTrap();
	void		guardGate();
	void		attack(const std::string& target);
	void		attack(ScavTrap& target);
};

#endif

