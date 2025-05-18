#include "ClapTrap.hpp"

int main()
{
	ClapTrap	trap1("David");
	ClapTrap	trap2("James");

	for (int i = 0; i < 11; i++)
	{
		trap1.attack("James");
		trap2.takeDamage(0);
	}
	for (int i = 0; i < 11; i++)
	{
		trap2.beRepaired(5);
	}
}
