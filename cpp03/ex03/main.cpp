#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap robot1 ("Rebecca");
	DiamondTrap robot2 ("David");
	DiamondTrap robot3 ("Kiwi");

	for (size_t i = 0; i < 26; i++)
	{
		robot1.attack(robot2);
		robot2.beRepaired(30);
		robot2.attack("Rebecca");
		robot1.beRepaired(30);
	}
	robot3.whoAmI();
	robot2.whoAmI();
	robot1.whoAmI();
}
