#include "ZombieHorde.hpp"
#include <ctime>
#include <iostream>

ZombieHorde::ZombieHorde(int N)
{
    this->zombies = 0;
    this->zombies = new Zombie[N];
    if (this->zombies == NULL)
        exit(0);

    this->zombies_count = N;
    std::srand(std::time(0));
    for (int i = 0; i < N; i++)
    {
        this->zombies[i].set_name(ZombieHorde::get_random_name());
        this->zombies[i].set_type(ZombieHorde::get_random_type());
    }
}

ZombieHorde::~ZombieHorde()
{
    delete[] this->zombies;
    return;
}

void
ZombieHorde::announce()
{
    for (int i = 0; i < this->zombies_count; i++)
        this->zombies[i].announce();
}

std::string
ZombieHorde::get_random_name()
{
    std::string names[] = {"Fat", "Pretty boy", "Hungry", "office plankton"};
    return (names[std::rand() % 4]);
}
std::string
ZombieHorde::get_random_type()
{
    std::string types[] = {"type_1", "type_2", "type_3", "type_4"};
    return (types[std::rand() % 4]);
}