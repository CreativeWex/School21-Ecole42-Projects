#include "HumanB.hpp"

void HumanB::setWeapon(Weapon &weapon)
{
	_type = &weapon;
}

void HumanB::attack()
{
	std::cout << this->_name << " attacks with their " << 
	_type->getType() << "\n";
}

HumanB::HumanB(std::string name)
{
	_name = name;
}

HumanB::~HumanB()
{

}
