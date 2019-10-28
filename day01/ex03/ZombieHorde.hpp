#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP
#include "Zombie.hpp"

class ZombieHorde
{
private:
    Zombie*     zombies;
    int         zombies_count;
    static std::string  get_random_name();
    static std::string  get_random_type();
public:
    ZombieHorde(int);
    ~ZombieHorde();
    void        announce();
};
#endif