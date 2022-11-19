#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		using FragTrap::_hitpoints; 
		using FragTrap::_attack_damage; 
		using ScavTrap::_energy_points; 
		using ScavTrap::attack;

		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap(DiamondTrap const & ref);
		DiamondTrap & operator=(DiamondTrap const & ref);
		void	whoAmI( void );
	private:
		std::string	_name;
};


#endif