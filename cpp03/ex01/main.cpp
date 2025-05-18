#include "ScavTrap.hpp"

int main()
{
	ScavTrap robot1 ("Rebecca");
	ScavTrap robot2 ("David");
	ScavTrap robot3 ("Kiwi");

	for (size_t i = 0; i < 26; i++)
	{
		robot1.attack(robot2);
		robot2.beRepaired(20);
		robot2.attack(robot1);
		robot1.beRepaired(20);
	}
	robot3.guardGate();
}
