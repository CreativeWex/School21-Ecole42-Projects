#include "Zombie.hpp"

Zombie*    zombieHorde( int N, std::string name )
{
    if (N <= 0)
    {
        return NULL;
    }

    Zombie *horde = new (std::nothrow) Zombie[N]; // nothrow - возвращает нулевой указатель при ошибке выделения памяти
    for (int i = 0; i < N; i++)
    {
        horde[i].setName(name);
    }
    return horde;
}