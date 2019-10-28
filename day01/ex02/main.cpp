#include "ZombieEvent.hpp"
#include <iostream>
#include <ctime>

int main()
{
    Zombie* zombie_1;
    Zombie* zombie_2;
    ZombieEvent event;

    event.setZombieType("world");
    zombie_1 = event.newZombie("hello");
    zombie_1->announce();
    delete zombie_1;

    event.setZombieType("");
    zombie_2 = event.newZombie("empty");
    zombie_2->announce();
    delete zombie_2;

    std::srand(std::time(0));
    event.setZombieType("random");
    event.randomChump();
    return (0);
}