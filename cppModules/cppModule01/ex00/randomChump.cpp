#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie ob = Zombie(name);
    ob.announce();
}