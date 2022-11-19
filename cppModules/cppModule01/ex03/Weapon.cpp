#include <iostream>
#include "Weapon.hpp"

std::string Weapon::getType() const
{
	return _type;
}

Weapon::Weapon(std::string type)
{
	_type = type;
}

void Weapon::setType(std::string type)
{
	_type = type;
}

Weapon::~Weapon()
{

}