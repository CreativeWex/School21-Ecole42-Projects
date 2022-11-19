#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon1) : _name(name), _type(weapon1)
{

}

HumanA::~HumanA()
{
	
}

void HumanA::attack()
{
	std::cout << _name << " attacks with their "
			  << _type.getType() << "\n";
}

