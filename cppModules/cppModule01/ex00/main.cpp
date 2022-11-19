#include "Zombie.hpp"

Zombie *newZombie(std::string);
void randomChump(std::string name);

int main()
{
    Zombie *biba = new Zombie("Biba");
    biba->announce();
    randomChump("Boba"); // Боба удалился из-за выхода из области видимости
    delete biba;
    
    std::cout<<"\n";

    Zombie *pupa = new Zombie("Pupa");
    pupa->announce();
    Zombie *lupa = new Zombie("Lupa");
    lupa->announce();
    delete pupa;
    delete lupa;

    std::cout<<"\n";

    randomChump("Soso");

    return 0;
}