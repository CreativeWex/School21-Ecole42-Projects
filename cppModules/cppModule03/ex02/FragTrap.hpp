#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap(FragTrap const & rhs);
		FragTrap & operator=(FragTrap const & rhs);
		~FragTrap();
		void attack(std::string const & target);
		void highFivesGuys(void);
};

#endif