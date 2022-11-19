# define YEL	"\x1B[33m"
# define RESET  "\x1B[0m"

#include "Zombie.hpp"

Zombie*    zombieHorde( int N, std::string name );

int main()
{
    Zombie *horde;
    int len;
    std::string name;

    len = 5;
    name = "Walking dead";
    std::cout << YEL "Arr len = " RESET << len << YEL "\nArr member name = " RESET << name  << "\n";
    horde = zombieHorde(len, name);
    std::cout << YEL "Ref to Horde = " RESET << horde << "\n";
    for (int i = 0; i < len; i++)
    {
        horde[i].announce();
    }
    delete[] horde;
    std::cout << "==================\n";

    len = 2;
    name = "Resident Evil";
    std::cout << YEL "Arr len = " RESET << len << YEL "\nArr member name = " RESET << name  << "\n";
    horde = zombieHorde(len, name);
    std::cout << YEL "Ref to Horde = " RESET << horde << "\n";
    for (int i = 0; i < len; i++)
    {
        horde[i].announce();
    }
    delete[] horde;
    std::cout << "==================\n";

    len = 0;
    name = "There is nothing";
    std::cout << YEL "Arr len = " RESET << len << YEL "\nArr member name = " RESET << name  << "\n";
    horde = zombieHorde(len, name);
    std::cout << YEL "Ref to Horde = " RESET << horde << "\n";
    for (int i = 0; i < len; i++)
    {
        horde[i].announce();
    }
    delete[] horde;
    std::cout << "==================\n";

    len = -1;
    name = "Minus one";
    std::cout << YEL "Arr len = " RESET << len << YEL "\nArr member name = " RESET << name  << "\n";
    horde = zombieHorde(len, name);
    std::cout << YEL "Ref to Horde = " RESET << horde << "\n";
    for (int i = 0; i < len; i++)
    {
        horde[i].announce();
    }
    delete[] horde;
    std::cout << "==================\n";

    return 0;
}
