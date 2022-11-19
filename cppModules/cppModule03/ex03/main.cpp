#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	std::string s1 = "Clyde";
	std::string s2 = "Scarlet";
	std::string s3 = "Fred";
	std::string s4 = "Diego";

	DiamondTrap	diamondtrap(s4);
	std::cout << std::endl;

	diamondtrap.takeDamage(14);
	diamondtrap.beRepaired(18);
	std::cout << std::endl;

	diamondtrap.attack(s2);
	diamondtrap.attack(s2);
	diamondtrap.attack(s2);
	std::cout << std::endl;

	diamondtrap.guardGate();
	diamondtrap.attack(s2);
	std::cout << std::endl;

	diamondtrap.highFivesGuys();
	std::cout << std::endl;

	diamondtrap.whoAmI();
	std::cout << std::endl;
	diamondtrap.beRepaired(18);

	diamondtrap.takeDamage(50);

	diamondtrap.takeDamage(50);

	diamondtrap.beRepaired(20);
	diamondtrap.attack(s2);

	std::cout << std::endl;
	return (0);
}