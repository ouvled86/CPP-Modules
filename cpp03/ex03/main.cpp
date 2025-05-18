#include "FragTrap.hpp"

int main()
{
	FragTrap robot1 ("Rebecca");
	FragTrap robot2 ("David");
	FragTrap robot3 ("Kiwi");

	for (size_t i = 0; i < 51; i++)
	{
		robot1.attack(robot2);
		robot2.beRepaired(30);
		robot2.attack(robot1);
		robot1.beRepaired(30);
	}
	robot3.highFivesGuys();
}
